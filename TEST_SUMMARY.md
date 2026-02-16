# Test Summary for Lab02 Hashing Program

## Testing Date
February 16, 2026

## Issues Fixed
1. **Syntax Error (Line 53)**: Fixed `std:size_t` → `std::size_t`
2. **Missing Header**: Added `#include <iomanip>` for `std::setw()` function

## Build Status
✅ **PASSED** - Program compiles successfully with g++ using C++11 standard

## Test Results

### Test 1: Generate Hash for Valid File
**Status**: ✅ PASSED
- **Input**: Selected option 1, provided file path "Text.txt"
- **Expected**: Program generates hash and stores it in hash_info.json
- **Actual**: Hash successfully generated (17366582753828138337) and stored correctly
- **Notes**: JSON file properly formatted with proper indentation

### Test 2: Verify Hash for Unmodified File
**Status**: ✅ PASSED
- **Input**: Selected option 2
- **Expected**: Program reads hash_info.json and verifies file integrity
- **Actual**: "Hash verified" message displayed
- **Notes**: Program correctly compares stored hash with newly calculated hash

### Test 3: Verify Hash for Modified File
**Status**: ✅ PASSED
- **Input**: Modified Text.txt content, then selected option 2
- **Expected**: Program detects file modification and fails verification
- **Actual**: "Hash not verified" message displayed
- **Notes**: Integrity check working correctly

### Test 4: Invalid File Path Handling
**Status**: ✅ PASSED
- **Input**: Selected option 1, provided "nonexistent.txt"
- **Expected**: Error message and prompt to try again
- **Actual**: "File not found, please try again." displayed, program re-prompts for file path
- **Notes**: Error handling works correctly without crashing

### Test 5: Exit via "end" Command
**Status**: ✅ PASSED
- **Input**: Typed "end" at file path prompt
- **Expected**: Program exits gracefully
- **Actual**: "Exiting program." displayed, program exits with code 1
- **Notes**: Alternative exit method works as designed

### Test 6: Invalid Menu Option
**Status**: ✅ PASSED
- **Input**: Selected option 9 (invalid)
- **Expected**: Error message and return to menu
- **Actual**: "Invalid option" displayed, menu re-displayed
- **Notes**: Input validation working correctly

### Test 7: Normal Exit via Menu
**Status**: ✅ PASSED
- **Input**: Selected option 0
- **Expected**: Program exits gracefully
- **Actual**: "Exiting program." displayed, program exits with code 0
- **Notes**: Normal exit works correctly

## Overall Assessment
**Status**: ✅ ALL TESTS PASSED

The program works as expected after fixing the syntax errors. All core functionalities are working:
- File hashing using std::hash
- JSON data persistence
- Hash verification
- Error handling
- User input validation
- Multiple exit methods

## Files Modified
1. `Lab02HashingProgram.cpp` - Fixed syntax errors
2. `.gitignore` - Created to exclude build artifacts

## Files Generated During Testing
- `hash_program` (executable, excluded via .gitignore)
- `hash_info.json` (program output, tracked in repo)
