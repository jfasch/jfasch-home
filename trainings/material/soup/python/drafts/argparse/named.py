import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-i', '--interval', type=float, help='interval (in seconds) that we retrieve samples')
parser.add_argument('-o', '--outputfilename', help='file to write samples to ("-" for stdout)')

args = parser.parse_args()

interval = args.interval
outputfilename = args.outputfilename

# ...
