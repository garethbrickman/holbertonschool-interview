#!/usr/bin/python3
""" reads stdin line by line and computes metrics """
import sys


if __name__ == "__main__":
    status = {"200": 0,
              "301": 0,
              "400": 0,
              "401": 0,
              "403": 0,
              "404": 0,
              "405": 0,
              "500": 0}
    count = 1
    file_size = 0

    def get_line(line):
        """ parse and grab data"""
        try:
            parsed_line = line.split()
            status_code = parsed_line[-2]
            if status_code in status.keys():
                status[status_code] += 1
            return int(parsed_line[-1])
        except Exception:
            return 0

    def print_stats():
        """print stats"""
        print("File size: {}".format(file_size))
        for key in sorted(status.keys()):
            if status[key]:
                print("{}: {}".format(key, status[key]))

    try:
        for line in sys.stdin:
            file_size += get_line(line)
            if count % 10 == 0:
                print_stats()
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
