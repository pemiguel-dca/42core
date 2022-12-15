#!/bin/bash
IFS=" ";ARG=(1 2 3 4 5 6); ./push_swap $ARG | ./checker_linux $ARG
