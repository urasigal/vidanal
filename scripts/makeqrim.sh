#!/bin/bash

DIRNAME="../qrimages/"

for i in {1..5000}
do
   qrencode -o  $DIRNAME$i`echo .png` i
done
