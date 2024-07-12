#!/bin/sh

echo "## Should be Ok\n\n"

echo "================================"
echo "./rush-02 0 | cat -e"
./rush-02 0 | cat -e
echo "expect 'zero'\n"

echo "================================"
echo "./rush-02 6 | cat -e"
./rush-02 6 | cat -e
echo "expect 'six'\n"

echo "================================"
echo "./rush-02 13 | cat -e"
./rush-02 13 | cat -e
echo "expect 'thirteen'\n"

echo "================================"
echo "./rush-02 52 | cat -e"
./rush-02 52 | cat -e
echo "expect 'fifty two'\n"

echo "================================"
echo "./rush-02 233 | cat -e"
./rush-02 233 | cat -e
echo "expect 'two hundred thirty three'\n"

echo "================================"
echo "./rush-02 343003424003 | cat -e"
./rush-02 343003424003 | cat -e
echo "expect 'three hundred forty three billion three million four hundred twenty four thousand three'\n"

echo "================================"
echo "./rush-02 9897456760023243540035032043 | cat -e"
./rush-02 9897456760023243540035032043 | cat -e
echo "nine octillion eight hundred ninety seven septillion four hundred fifty six sextillion seven hundred sixty quintillion twenty three quadrillion two hundred forty three trillion five hundred forty billion thirty five million thirty two thousand forty three'\n"

echo "================================"
echo "./rush-02 999999999999999999999999999999999999999 | cat -e"
./rush-02 999999999999999999999999999999999999999 | cat -e
echo "nine hundred ninety nine undecillion nine hundred ninety nine decillion nine hundred ninety nine nonillion nine hundred ninety nine octillion nine hundred ninety nine septillion nine hundred ninety nine sextillion nine hundred ninety nine quintillion nine hundred ninety nine quadrillion nine hundred ninety nine trillion nine hundred ninety nine billion nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine'\n"

echo "================================"
echo "./rush-02 +1234 | cat -e"
./rush-02 +1234 | cat -e
echo "expect 'one thousand two hundred thirty four'\n"

echo "\n\n## Sould be Same if swapped dict\n\n"

echo "================================"
echo "./rush-02 0 | cat -e"
./rush-02 0 | cat -e
echo "expect 'zero'\n"
echo "\n./rush-02 ./dicts/swaped-numbers.dict 0 | cat -e"
./rush-02 ./dicts/swaped-numbers.dict 0 | cat -e
echo "expect 'zero'\n"

echo "================================"
echo "./rush-02 +1234 | cat -e"
./rush-02 +1234 | cat -e
echo "expect 'one thousand two hundred thirty four'\n"
echo "\n./rush-02 ./dicts/swaped-numbers.dict +1234 | cat -e"
./rush-02 ./dicts/swaped-numbers.dict +1234 | cat -e
echo "expect 'one thousand two hundred thirty four'\n"

echo "\n\n## Should be Error\n\n"

echo "================================"
echo "./rush-02 Desktop/42tokyo/798345 98765 | cat -e"
./rush-02 Desktop/42tokyo/798345 98765 | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 ./dicts/error-numbers.dict 234 | cat -e"
./rush-02 ./dicts/error-numbers.dict 234 | cat -e
echo "expect 'Dict Error: because key is not unique'\n"

echo "================================"
echo "./rush-02 ./dicts/hoge.dica 234 | cat -e"
./rush-02 ./dicts/hoge.dica 234 | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 -233 | cat -e"
./rush-02 -233 | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 kaskbj | cat -e"
./rush-02 kaskbj | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 | cat -e"
./rush-02 | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 + | cat -e"
./rush-02 + | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 "" | cat -e"
./rush-02 "" | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 "1000000000000000000000000000000000000000" | cat -e"
./rush-02 "1000000000000000000000000000000000000000" | cat -e
echo "expect 'Dict Error: because too big '\n"

echo "================================"
echo "./rush-02 765%3 | cat -e"
./rush-02 765%3 | cat -e
echo "expect 'Error'\n"

echo "================================"
echo "./rush-02 ç©∂∆˙¥¥© | cat -e"
./rush-02 ç©∂∆˙¥¥© | cat -e
echo "expect 'Error'\n"
