# ?
Given a number `N`, integer or real number. Please return a string which is the English pronunciation of that number.
The rules is as follow:
- `N` may consists of two parts: `intergral + '.' + decimal`. As `N` could just be an integer, the dot and decimal part may not exist.
- For integral part, you should read just like in English, but without 'and' between the units. For example:
`123` is `One hundred twenty three`, `1010` is `One thousand ten`, `123678` is `One hundred twenty three thousand six hundred seventy eight`. The largest unit is `billion`.
- For real number, append the word `point` between integral pronounciation and decimal pronunciation. As for decimal pronuciation, just read out each digit from left to right. For example: `1.21` is `One point two one`.
- For invalid cases, output `-1`. Invalid cases are: Integer that starts with `0..` with exception of `0`, number contains other characters than digits and dots, number contains more than one dot, or number contains a dot but decimal part is empty. For other cases, please handle normally as noted above.
- Notice that the final string must has the first character capitalized.

# Sample test
| INPUT |                 OUTPUT                 |
|-------|----------------------------------------|
| 12    | Twelve                                 |
| 123678| One hundred twenty three thousand six hundred seventy eight|
| 1.1   | One point one |
| 01    | -1 |
| 0.010 | One point zero one zero |
