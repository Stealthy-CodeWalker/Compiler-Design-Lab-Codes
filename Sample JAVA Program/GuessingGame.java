import java.util.Random;
import java.util.Scanner;

public class GuessingGame {
    public static void main(String[] args) {
        Random random = new Random();
        int randomNumber = random.nextInt(10) + 1; // Generates a random number between 1 and 10

        Scanner scanner = new Scanner(System.in);
        int guess;
        boolean correctGuess = false;

        System.out.println("Welcome to the Guessing Game!");

        for (int attempts = 1; attempts <= 5 && !correctGuess; attempts++) {
            System.out.println("Attempt " + attempts);
            System.out.print("Guess a number between 1 and 10: ");
            guess = scanner.nextInt();

            if (guess < 1 || guess > 10) {
                System.out.println("Please enter a number between 1 and 10.");
            } else if (guess == randomNumber) {
                System.out.println("Congratulations! You guessed the correct number.");
                correctGuess = true;
            } else {
                System.out.println("Sorry, that's not the correct number. Try again.");
            }
        }

        if (!correctGuess) {
            System.out.println("Sorry, you have used all your attempts. The correct number was " + randomNumber + ".");
        }

        scanner.close();
    }
}