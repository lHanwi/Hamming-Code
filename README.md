# Hamming Code

## Description

Hamming Code is an error-detection method used in digital communications. The process follows these steps:

Redundancy Calculation: First, we determine the number of parity bits (r) to be added to the message. 
The number of parity bits is calculated based on the formula: 
2^r <= m+r+1, 
𝑚 is the length of the original data string.

-Positioning: These parity bits are placed at specific positions that are powers of two (e.g., 1, 2, 4, 8, …).

-Parity Calculation: Each parity bit is responsible for checking a specific subset of the data bits. For example:
The parity bit at position 1 checks every other bit (1, 3, 5, …). If the count of '1’s in this group is even, the parity bit is set to 0; if odd, it is set to 1.
The parity bit at position 2 checks bits in a pattern of 2 (skipping two bits, checking two bits, etc.).
This pattern continues for all subsequent parity positions.

-Encoding: Once all parity bits are calculated, they are inserted into their respective positions, and the final encoded message is transmitted.


Error Detection at the Receiver:
When the receiver gets the data, it applies the same algorithm to recalculate the parity bits. If the newly calculated parity bits do not match the received parity bits, it indicates that an error has occurred during transmission.
