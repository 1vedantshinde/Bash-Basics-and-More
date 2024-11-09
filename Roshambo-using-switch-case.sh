#!/bin/bash
# Function to play Rock-Paper-Scissors
playGame() {
choices=("Rock" "Paper" "Scissors")
computer_choice=${choices[$((RANDOM % 3))]}
echo "Choose one: (1) Rock (2) Paper (3) Scissors"
read -p "Your choice: " user_choice

case $user_choice in
1)
user_pick="Rock"
;;
2)
user_pick="Paper"
;;
3)
user_pick="Scissors"
;;
*)
echo "Invalid Choice. Try again"
return
;;
esac

echo "You chose: $user_pick"
echo "Computer chose: $computer_choice"

# Determining the winner
if [ "$user_pick" == "$computer_choice" ]; then
echo "It's a tie!"
elif [ "$user_pick" == "Rock" ] && [ "$computer_choice" == "Scissors" ]; then
echo "You win"
elif [ "$user_pick" == "Paper" ] && [ "$computer_choice" == "Rock" ]; then
echo "You win"
elif [ "$user_pick" == "Scissors" ] && [ "$computer_choice" == "Paper" ]; then
echo "You win"
else
echo "Computer wins"
fi
}

# Menu Function
menu() {
echo "Welcome to Rock-Paper-Scissors"
echo "1) Play Game"
echo "2) Quit"

read -p "Please enter your choice: " choice

if [ "$choice" -eq 1 ]; then
playGame
elif [ "$choice" -eq 2 ]; then
echo "Goodbye!"
exit 0
else
echo "Invalid option, please try again."
fi
}

# Loop the menu until the user chooses to quit
while true; do
menu
done
