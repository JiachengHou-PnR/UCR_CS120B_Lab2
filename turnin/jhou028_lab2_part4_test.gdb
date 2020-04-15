# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Add tests below

echo Running total calc tests..."\n

# No rounding
test "PIN A:0x28 B:0x28 C:0x28 => PORTD: 0x78 (40 + 40 + 40)"
setPINA 0x28
setPINB 0x28
setPINC 0x28
continue 5
expectPORTD 0x78
checkResult

# Round up
test "PIN A:0x28 B:0x26 C:0x28 => PORTD: 0x78 (40 + 38 + 40)"
setPINA 0x28
setPINB 0x26
setPINC 0x28
continue 5
expectPORTD 0x78
checkResult

# Round down
test "PIN A:0x28 B:0x29 C:0x28 => PORTD: 0x78 (40 + 41 + 40)"
setPINA 0x28
setPINB 0x29
setPINC 0x28
continue 5
expectPORTD 0x78
checkResult

echo \nRunning overweight tests..."\n
# No rounding, no overflow 
test "PIN A:0x31 B:0x32 C:0x31 => PORTD: 0x95 (148)"
setPINA 0x31
setPINB 0x32
setPINC 0x31
continue 5
expectPORTD 0x95
checkResult

# Round up, no overflow 
test "PIN A:0x46 B:0x46 C:0x46 => PORTD: 0xD5 (210)"
setPINA 0x46
setPINB 0x46
setPINC 0x46
continue 5
expectPORTD 0xD5
checkResult

# Overflow 
test "PIN A:0x64 B:0x64 C:0x64 => PORTD: 0xFD (300)"
setPINA 0x64
setPINB 0x64
setPINC 0x64
continue 5
expectPORTD 0xFD
checkResult

echo \nRunning unbalance tests..."\n
# A < B, no overweight, no overflow
test "PIN A:0x14 B:0x0A C:0x6A => PORTD: 0x88 (136)"
setPINA 0x14
setPINB 0x0A
setPINC 0x6A
continue 5
expectPORTD 0x8A
checkResult

# A > B, no overweight, no overflow
test "PIN A:0x6A B:0x0A C:0x14 => PORTD: 0x88 (136)"
setPINA 0x6A
setPINB 0x0A
setPINC 0x14
continue 5
expectPORTD 0x8A
checkResult



# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
