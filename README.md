# Object Serialization and Deserialization

## Problem Statement:
You have an object of a class, and you want to either store that object permanently in secondary memory or send the object to another system via networking. The problem is that objects in programming languages like C++ exist in RAM as complex structures, consisting of references, different data types, and memory addresses. These in-memory representations cannot be directly stored or transmitted. This is where serialization and deserialization come in.

**Serialization** is the process of converting an object into a format (such as a byte stream or string) that can be easily saved to a file, sent over a network, or stored in a database. Once the object is serialized, it can be stored or transmitted in a more universal format, like binary or text. **Deserialization** is the reverse process—reconstructing the original object from the serialized data, restoring it to its original state in memory. Serialization is widely used in networking, file handling, and inter-process communication.

In this assignment, you are required to implement serialization and deserialization methods for two classes: Student and Course. The goal is to encode the data of objects from these classes into a binary string format and then decode them back into objects.

- Class **`Student`** contains only `string` variables, making its serialization straightforward.
- Class **`Course`** contains variables of different data types: `string`, `int`, and `float`, requiring a more elaborate serialization method.

## Serialization of `Student`:
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
rollNumber = "CS101"
dob = "01/01/2000"
```

**Serialization Steps:**
1. Concatenate the variables:
```
"Alice$CS101$01/01/2000"
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
1 -> 00110001
0 -> 00110000
1 -> 00110001
$ -> 00100100
0 -> 00110000
1 -> 00110001
/ -> 00101111
0 -> 00110000
1 -> 00110001
/ -> 00101111
2 -> 00110010
0 -> 00110000
0 -> 00110000
0 -> 00110000
```
3. The final binary output will be:
```
010000010110110001101001011000110110010100100100010000110101001100110001001100010010010000100100001011110011000000110000011110001100010011111001101011011000001011001110000110100011111000110000
```

**Deserialization Steps:**
1. Given a serialized binary string:
```
010000010110110001101001011000110110010100100100010000110101001100110001001100010010010000100100001011110011000000110000011110001100010011111001101011011000001011001110000110100011111000110000
```
2. Split the binary string into 8-bit segments:
```
01000001 01101100 01101001 01100011 01100101 00100100 01000011 01010011 00110001 00110000 00110001 00100100 00110000 00110001 00101111 00110000 00110001 00101111 00110010 00110000 00110000
```
3. Convert each 8-bit segment back to characters (ASCII representation):
```
A, l, i, c, e, $, C, S, 1, 0, 1, $, 0, 1, /, 0, 1, /, 2, 0, 0
```
4. The final output after deserialization will be:
```
Alice CS101 01/01/2000
```

## Serialization of `Course`:
The `Course` class contains the following variables:
- `string ID`
- `int noOfRegisteredStudents` (4 bytes)
- `float averageMarks` (4 bytes)

The serialization process involves the following steps:
- For the `ID`, write the size of the string in bytes using 1 byte (since the size of `ID` will always be ≤ 255), followed by the actual string data.
- Directly serialize `noOfRegisteredStudents` and `averageMarks` as they have fixed sizes.
- **Note:** You do not need to compute the IEEE 754 representation of `averageMarks`. Instead, access the bit pattern directly using bitwise operators.

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
Size of `ID`: 6 (binary: `00000110`)

ASCII values of `C`, `S`, `6`, `1`, `5`, `0`:
C -> 01000011
S -> 01010011
6 -> 00110110
1 -> 00110001
5 -> 00110101
0 -> 00110000
```

3. Serialize `noOfRegisteredStudents` (60):
```
Binary: 00000000000000000000000000111100
```

4. Serialize `averageMarks` (63.5):
```
Binary in IEEE 754 format (accessed directly): 01000001011111100000000000000000
```

5. The final serialized output in binary will be:
```
00000110 01000011 01010011 00110110 00110001 00110101 00110000 00000000000000000000000000111100 01000001011111100000000000000000
```


**Deserialization Steps:**
1. Given a serialized binary string:
```
00000110 01000011 01010011 00110110 00110001 00110101 00110000 00000000000000000000000000111100 01000001011111100000000000000000
```
2. The deserialization process involves reading the size of the `ID` and extracting the respective values:
```
1. Read the first byte to get the size of `ID` (6 bytes).
2. Read the next 6 bytes to get `ID` (`CS6150`).
3. Read the next 4 bytes directly as `noOfRegisteredStudents` (60).
4. Read the next 4 bytes directly as `averageMarks` (63.5).
```

The final output after deserialization will be:
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
Each line of the input will contain either a serialization or deserialization command.

- For serialization: serialize <ClassName> <Variable1> <Variable2> ... <VariableN>
- For deserialization: deserialize <ClassName> <SerializedInput>


## Output Format:
- For serialization, the output will be the serialized representation in binary format (a string of `0`s and `1`s).
- For deserialization, the output will be the contents of the class variables in the original order, separated by spaces.

## Sample Input and Output
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
