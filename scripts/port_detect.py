#!/usr/bin/env python3
"""Auto-detect XBee and Xsens serial ports by USB descriptor."""

import sys
import serial.tools.list_ports


# Digi XBee USB adapters use FTDI chips
FTDI_VID = 0x0403
# Xsens MTi VID
XSENS_VID = 0x2639

XBEE_KEYWORDS = ('xbee', 'digi',)
XSENS_KEYWORDS = ('xsens', 'mti',)


def _describe(port):
    parts = [port.device]
    if port.description and port.description != 'n/a':
        parts.append(port.description)
    if port.manufacturer:
        parts.append(f'mfr={port.manufacturer}')
    if port.vid is not None:
        parts.append(f'VID:PID={port.vid:04X}:{port.pid:04X}')
    return '  '.join(parts)


def _score_xbee(port):
    """Higher score = more likely to be an XBee."""
    score = 0
    text = ' '.join([
        port.description or '',
        port.manufacturer or '',
        port.product or '',
    ]).lower()
    if any(kw in text for kw in XBEE_KEYWORDS):
        score += 10
    if port.vid == FTDI_VID:
        score += 3
    if any(kw in text for kw in XSENS_KEYWORDS):
        score -= 20
    if port.vid == XSENS_VID:
        score -= 20
    return score


def _score_xsens(port):
    """Higher score = more likely to be an Xsens."""
    score = 0
    text = ' '.join([
        port.description or '',
        port.manufacturer or '',
        port.product or '',
    ]).lower()
    if any(kw in text for kw in XSENS_KEYWORDS):
        score += 10
    if port.vid == XSENS_VID:
        score += 10
    return score


def _pick_best(ports, score_fn, label):
    if not ports:
        return None

    scored = [(score_fn(p), p) for p in ports]
    scored.sort(key=lambda x: x[0], reverse=True)

    if scored[0][0] > 0:
        best = scored[0][1]
        print(f'[port_detect] Auto-detected {label}: {_describe(best)}', file=sys.stderr)
        return best.device

    return None


def _prompt_user(candidates, label):
    print(f'\nMultiple serial ports found — select the {label}:', file=sys.stderr)
    for i, p in enumerate(candidates, 1):
        print(f'  {i}) {_describe(p)}', file=sys.stderr)
    print(f'  0) None / skip', file=sys.stderr)
    while True:
        try:
            choice = input(f'  {label}> ').strip()
        except (KeyboardInterrupt, EOFError):
            return None
        if choice == '0':
            return None
        try:
            idx = int(choice) - 1
            if 0 <= idx < len(candidates):
                return candidates[idx].device
        except ValueError:
            pass
        print(f'  Enter 1-{len(candidates)} or 0 to skip.', file=sys.stderr)


def find_xbee_port(exclude_ports=None):
    """Find the XBee serial port.

    Returns the port string (e.g. 'COM3' or '/dev/ttyUSB0') or None.
    """
    all_ports = sorted(serial.tools.list_ports.comports(), key=lambda p: p.device)
    exclude = set(exclude_ports or [])
    candidates = [p for p in all_ports if p.device not in exclude]

    if not candidates:
        print('[port_detect] No serial ports found.', file=sys.stderr)
        return None

    best = _pick_best(candidates, _score_xbee, 'XBee')
    if best:
        return best

    if len(candidates) == 1:
        port = candidates[0]
        print(f'[port_detect] Only one serial port available, using it for XBee: {_describe(port)}', file=sys.stderr)
        return port.device

    return _prompt_user(candidates, 'XBee')


def find_xsens_port(exclude_ports=None):
    """Find the Xsens MTi serial port.

    Returns the port string (e.g. '/dev/ttyUSB1') or None.
    """
    all_ports = sorted(serial.tools.list_ports.comports(), key=lambda p: p.device)
    exclude = set(exclude_ports or [])
    candidates = [p for p in all_ports if p.device not in exclude]

    if not candidates:
        print('[port_detect] No serial ports found.', file=sys.stderr)
        return None

    best = _pick_best(candidates, _score_xsens, 'Xsens')
    if best:
        return best

    return _prompt_user(candidates, 'Xsens')


def find_all_ports():
    """Return (xbee_port, xsens_port) auto-detecting both.

    Finds XBee first, then Xsens from the remaining ports.
    """
    xbee = find_xbee_port()
    xsens = find_xsens_port(exclude_ports=[xbee] if xbee else None)
    return xbee, xsens


if __name__ == '__main__':
    print('Scanning serial ports...\n')
    all_ports = serial.tools.list_ports.comports()
    if not all_ports:
        print('No serial ports found.')
        sys.exit(0)

    print('All serial ports:')
    for p in sorted(all_ports, key=lambda p: p.device):
        print(f'  {_describe(p)}')
    print()

    xbee, xsens = find_all_ports()
    print(f'\nResult:  XBee={xbee or "not found"}  Xsens={xsens or "not found"}')
