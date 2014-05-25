#!/bin/bash

for n in {1..10}
do
    sudo userdel -r test$n
done

cat /etc/passwd
