import sys
import re


def polyscripter(input_code):
    buffer = []
    input_list = list(input_code)

    for ch in input_list:
        buffer.append()

    output_code = "".join(output_list)

    return output_code


if __name__ == "__main__":
    input_filepath = sys.argv[1]
    input_file_extension = input_filepath.split(".")[-1]
    output_filepath = "output.{}".format(input_file_extension)

    with open(input_filepath) as f:
        input_code = f.read()

    output_code = polyscripter(input_code)

    with open(output_filepath, "w+") as f:
        f.write(output_code)
