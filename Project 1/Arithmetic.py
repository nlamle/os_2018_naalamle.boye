# A programme to perform simple arithmetic.
#
# Print information about the programme
def printMenu():
    print('I understand the following commands:\n'+
          'ADD <value>\nSUBTRACT <value>\n'+
          'MULTIPLY <value>\nDIVIDE <value>\n' +
          'UNDO\nREDO\nEND\n')

# Read a command any arguments
def readCommand():
    command = input('Please enter a command: ')
    args = command.lower().split()
    return args

# The main program
def main():
    x = float(input('Pick a starting number. '))
    printMenu()

    print('Your starting value is ' + str(x))
    args = readCommand()
    while (args[0] != 'end'):
        if (args[0] == 'add'):
            x = x + float(args[1])
        elif (args[0] == 'subtract'):
            x = x - float(args[1])
        elif (args[0] == 'multiply'):
            x = x * float(args[1])
        elif (args[0] == 'divide'):
            x = x / float(args[1])

        print('Executed ' + ' '.join(args) +
              ': Current value is ' + str(x))
        args = readCommand()

    print('Your final value was',x)
    print('Goodbye!')

main()
