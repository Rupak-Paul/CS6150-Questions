# Object Serialization and Deserialization

## Problem Statement:
You have an object of a class, and you want to either store that object permanently in secondary memory or send the object to another system via networking. The problem is that objects in programming languages like C++ exist in RAM as complex structures, consisting of references, different data types, and memory addresses. These in-memory representations cannot be directly stored or transmitted. This is where serialization and deserialization come in.

**Serialization** is the process of converting an object into a format (such as a byte stream or string) that can be easily saved to a file, sent over a network, or stored in a database. Once the object is serialized, it can be stored or transmitted in a more universal format, like binary or text. **Deserialization** is the reverse process—reconstructing the original object from the serialized data, restoring it to its original state in memory. Serialization is widely used in networking, file handling, and inter-process communication.

In this assignment, you are required to implement serialization and deserialization methods for two classes: Student and Course. The goal is to encode the data of objects from these classes into a binary string format and then decode them back into objects.

- Class **`Student`** contains only `string` variables, making its serialization straightforward.
- Class **`Course`** contains variables of different data types: `string`, `int`, and `float`, requiring a more elaborate serialization method.

## Serialization of Student:
The `Student` class contains the following `string` variables:
- `name`
- `rollNumber`
- `dob`

Since all class variables are of type `string`, we can use a simple serialization method:
- Concatenate the variables using the `$` character as a delimiter.
- Convert the concatenated string into a binary format by transforming each character into its ASCII binary representation.

### Example:
Given a `Student` object with:
```
name = "Alice"
rollNumber = "CS24M1"
dob = "14/10/2024"
```

**Serialization Steps:**
1. Concatenate the variables:
```
Alice$CS24M1$14/10/2024
```
2. Convert the concatenated string into its ASCII binary representation:
```
A -> 01000001
l -> 01101100
i -> 01101001
c -> 01100011
e -> 01100101
$ -> 00100100
C -> 01000011
S -> 01010011
2 -> 00110010
4 -> 00110100
M -> 01001101
1 -> 00110001
$ -> 00100100
1 -> 00110001
4 -> 00110100
/ -> 00101111
1 -> 00110001
0 -> 00110000
/ -> 00101111
2 -> 00110010
0 -> 00110000
2 -> 00110010
4 -> 00110100
```
3. The final binary output after serialization will be:
```
0100000101101100011010010110001101100101001001000100001101010011001100100011010001001101001100010010010000110001001101000010111100110001001100000010111100110010001100000011001000110100
```

**Deserialization Steps:**
1. Given a serialized binary string:
```
0100000101101100011010010110001101100101001001000100001101010011001100100011010001001101001100010010010000110001001101000010111100110001001100000010111100110010001100000011001000110100
```
2. Split the binary string into 8-bit segments:
```
01000001 01101100 01101001 01100011 01100101 00100100 01000011 01010011 00110010 00110100 01001101 00110001 00100100 00110001 00110100 00101111 00110001 00110000 00101111 00110010 00110000 00110010 00110100
```
3. Convert each 8-bit segment back to characters (ASCII representation):
```
A, l, i, c, e, $, C, S, 2, 4, M, 1, $, 1, 4, /, 1, 0, /, 2, 0, 2, 4
```
4. The final output after deserialization will be:
```
Alice CS24M1 14/10/2024
```

## Serialization of Course:
The `Course` class contains the following variables:
- `string ID`
- `int noOfRegisteredStudents` (4 bytes)
- `float averageMarks` (4 bytes)

The serialization process involves the following steps:
- For the `ID`, write the size of the string in bytes using 1 byte (since the size of `ID` will always be ≤ 255), followed by the actual string data.
- Directly write the underlying bit pattern of `noOfRegisteredStudents` and `averageMarks` as they have fixed sizes.

### Example:
Given a `Course` object with:
```
ID = "CS6150"
noOfRegisteredStudents = 60
averageMarks = 63.5
```

**Serialization Steps:**
1. Serialize `ID`:
```
Size of `ID` in bytes:
00000110 (6)

ASCII values of `C`, `S`, `6`, `1`, `5`, `0`:
C -> 01000011
S -> 01010011
6 -> 00110110
1 -> 00110001
5 -> 00110101
0 -> 00110000

Serialized ID:
00000110010000110101001100110110001100010011010100110000
```
2. Serialize `noOfRegisteredStudents`:
```
00000000000000000000000000111100 (underlying bit pattern of noOfRegisteredStudents)
```
3. Serialize `averageMarks`:
```
01000010011111100000000000000000 (underlying bit pattern (IEEE 754) of averageMarks)
```
4. The final serialized output in binary will be:
```
000001100100001101010011001101100011000100110101001100000000000000000000000000000011110001000010011111100000000000000000
```

**Deserialization Steps:**
1. Given a serialized binary string:
```
000001100100001101010011001101100011000100110101001100000000000000000000000000000011110001000010011111100000000000000000
```
2. The deserialization process involves the following steps:
```
1. Read the first byte to get the size of ID (6).
2. Read the next 6 bytes to get ID (CS6150).
3. Read the next 4 bytes directly as noOfRegisteredStudents (60).
4. Read the next 4 bytes directly as averageMarks (63.5).
```
3. The final output after deserialization will be:
```
CS6150 60 63.5
```

## Tasks:
You need to implement the following methods:
1. `serializeStudent(Student student)` - Takes a `Student` object and returns a serialized binary string.
2. `deserializeStudent(string binary)` - Takes a serialized binary string and returns the original `Student` object.
3. `serializeCourse(Course course)` - Takes a `Course` object and returns a serialized binary string.
4. `deserializeCourse(string binary)` - Takes a serialized binary string and returns the original `Course` object.

## Input Format:
- The input will contain only one line.
- The first word will be either `serialize` or `deserialize`.
  
- If the command is `serialize`, the next word will be the class name (`Student` or `Course`), followed by the class variable values:
  - For `Student`: `name`, `rollNumber`, `dob`.
  - For `Course`: `ID`, `noOfRegisteredStudents`, `averageMarks`.

- If the command is `deserialize`, the next word will be the class name (`Student` or `Course`), followed by the serialized binary string.

## Output Format:
- For serialization, the output will be the serialized representation in binary format (a string of `0`s and `1`s).
- For deserialization, the output will be the contents of the class variables in the original order, separated by spaces.

## Sample Inputs and Outputs
**Sample Input 1:**
```
serialize Student Alice CS101 01/01/2000
```
**Sample Output 1:**
```
010000010110110001101001011000110110010100100100010000110101001100110001001100010010010000100100001011110011000000110000011110001100010011111001101011011000001011001110000110100011111000110000
```
**Sample Input 2:**
```
deserialize Student 010000010110110001101001011000110110010100100100010000110101001100110001001100010010010000100100001011110011000000110000011110001100010011111001101011011000001011001110000110100011111000110000
```
**Sample Output 2:**
```
Alice CS101 01/01/2000
```
**Sample Input 3:**
```
serialize Course CS6150 60 63.5
```
**Sample Output 3:**
```
00000110 01000011 01010011 00110110 00110001 00110101 00110000 00000000000000000000000000111100 01000001011111100000000000000000
```
**Sample Input 4:**
```
deserialize Course 00000110 01000011 01010011 00110110 00110001 00110101 00110000 00000000000000000000000000111100 010
```
**Sample Output 4:**
```
Course CS6150 60 63.5
```
