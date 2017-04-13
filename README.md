# Ingress Passcode Analyser
Help to solve encrypted Ingress passcodes.

## Supported ciphers so far
- Reverse
- Atbash (alphanumeric, hex)
- ROT N (alphanumeric)
- Skip N
- Base64
- Numeric digits replaced by two-letter combinations (e.g. 2 replaced by "tw")

## Usage
Type `-help` after executable name for help screen.

| Command | Action                              |
|---------|-------------------------------------|
| `a`     | Atbash (alphanumeric)               |
| `h`     | Atbash (hex)                        |
| `t[num]`| Rot[num] (alphanumeric)             |
| `l`     | replace two-letter written digits   |
| `s[num]`| skip [num]                          |
| `b`     | Base64                              |
| `o`     | view original code                  |
| `O`     | reset current code to the original  |
| `e`     | exit                                |