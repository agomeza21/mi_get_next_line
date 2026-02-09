*This project was created as part of the 42 curriculum by agomez-a.*

## DESCRIPTION

**get_next_line** is a C function that reads and returns a line from a file descriptor, including the newline character `\n` if it exists.

The project teaches fundamental C programming concepts such as:
- Dynamic memory management
- Static variables
- Buffer handling
- Managing multiple file descriptors

The function must be able to read from files, stdin, and correctly handle edge cases such as files without a final newline, empty files, and EOF.

## INSTRUCTIONS

The project requires defining the buffer size (`BUFFER_SIZE`) at compile time:  
```cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c```  
To check for memory leaks use:  
```valgrind --leak-check=full --show-leak-kinds=all ./a.out```

## RESOURCES

### Documentation and References
- Online resources for clarifying concepts.
- Guidance and help from classmates when needed.

### Use of AI
**Debugging and error correction:**
- Identification of memory leaks through Valgrind report analysis
- Detection of use-after-free and double-free errors
**Testing:**
- Creation of test cases for multiple file descriptors
**Documentation:**
- Assistance in writing this README
- Algorithm explanation and technical justification
The AI **did not write** the main code of the project, but was used as a support tool for debugging and understanding concepts.

## ALGORITHM

The algorithm uses a **single static pointer** (`static char *storage`) to maintain state between successive function calls.  
On each call, it checks if `storage` contains a newline character:  
If found, it extracts and returns the line up to and including `\n`, storing the remainder for the next call.  
If no newline is found, it copies the current content to a temporary buffer (`tmp`), reads the next BUFFER_SIZE bytes into `storage`, and repeats the process, accumulating content in `tmp` until a newline or EOF is encountered.  
When EOF is reached, any remaining content in `tmp` is returned as the final line.