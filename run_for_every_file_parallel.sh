#!/bin/bash

# The following will run the ./parallel_script.sh taking
# each file in "./data/" as the first (and only) argument.
# Will try to run 4 processes in parallel

ls ./data/* | parallel -j4 "./parallel_script.sh {}"

