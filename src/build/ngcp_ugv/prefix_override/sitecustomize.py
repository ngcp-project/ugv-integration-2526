import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ugv/NGCP/NGCP_25_26/ugv-integration-2526/src/install/ngcp_ugv'
