# shellcheck disable=SC2045
for f in `ls -1 *.c`; do
  # shellcheck disable=SC2046
  gcc -std=c18 -Wall $f -o `echo $f |  sed -e 's/\.c//'` -lm
done
