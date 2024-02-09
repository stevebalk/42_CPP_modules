#!/bin/bash

# Create a named pipe
pipe=/tmp/phonebook_pipe
mkfifo "$pipe"

# Start the C++ program, redirecting its stdin to the named pipe
./phonebook < "$pipe" &

# Function to simulate input
simulate_input() {
    echo "$1" > "$pipe"
}


# Test case 1: Adding a contact
for number in {1..8}
do
	simulate_input "1"
	simulate_input "Jack"
	simulate_input "O'Neil"
	simulate_input "Jack"
	simulate_input "0172555555"
	simulate_input "Dark Secret huuuhhhuuu"
done

simulate_input "2"
simulate_input "1"

for number in {1..8}
do
	simulate_input "1"
	simulate_input "Bob"
	simulate_input "Odenkirk"
	simulate_input "Bobby"
	simulate_input "0163444444"
	simulate_input "OMG I'm Bob Odenkirk"
done

simulate_input "2"
simulate_input "1"

simulate_input "1"
simulate_input "Samantha"
simulate_input "Carter"
simulate_input "Sam"
simulate_input "0172555555"
simulate_input "Dark Secret huuuhhhuuu"

# Test case 2: Searching for a contact
simulate_input "2"
simulate_input "1"

# # Test case 3: Exiting the program
# simulate_input "0"

# Clean up
rm "$pipe"