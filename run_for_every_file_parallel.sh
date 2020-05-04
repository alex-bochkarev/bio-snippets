#!/bin/bash

ls ./data/* | parallel "./parallel_script.sh {}"
