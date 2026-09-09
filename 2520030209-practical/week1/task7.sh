#!/bin/bash
mkdir -p permission_lab && cd permission_lab
echo "Permission Test" > test.txt
chmod -r test.txt
cat test.txt 2>/dev/null || echo "Read permission denied successfully"
chmod +r test.txt
chmod -w test.txt
echo "Modify" >> test.txt 2>/dev/null || echo "Write permission denied successfully"
chmod +w test.txt
chmod -x test.txt
./test.txt 2>/dev/null || echo "Execute permission denied successfully"
