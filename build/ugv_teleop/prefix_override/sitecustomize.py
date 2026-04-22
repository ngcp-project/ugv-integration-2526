import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ugvjetson2025/ugv-integration-2526/install/ugv_teleop'
