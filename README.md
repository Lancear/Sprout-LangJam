# Sprout Programming Language
(Created during the Repl.it Programming Lang Jam 2020)
Authors: @czapek, @darkmagic1, @erzis, @kspalaiologos, @Zirruedo
Team: @LangJamSprout

## Welcome to the Sprout Programming Language!
Our goal was to combine functional programming with object oriented programming instead of seeing them as two opposites.
A core idea of our language was to add events into the language directly. 
Our language-syntax is inspired by the c-familiy, to make it as comfortable as possible for new programmers to learn our language.
We tried to make keywords customizable or extendable, but we decided not to do it to keep the language simple.

# Features
* Supported Types: Integers, Characters, Booleans, Strings 
* Immutables and Mutables
* Functions
* String Concatination with any type
* Ability to write comments
* Type inference in variables
* Ternary Expressions
* Strong typechecking
* Basic console io

# Future Features
Unfortunatly we didn't have enough time to implement all our ideas, that ment that we only got the basics done which is listed at #Features.
To showcase some of the ideas we had in mind, here is one simple code example:
```
class Todo {
  let text: string;
  let done = false;

  // event handlers receive the todo as an argument
  event completed(Todo);

  fn Todo(text: string) {
    this.text= text;
  }

  fn complete() {
    let todo = new Todo(this.text, next);
    emit completed(todo);
    return todo;
  }
}

@Todo.completed(todo) {
  Console.writeln("Completed any todo, " + todo.text);
}

fn main() {
  let todo1 = Todo("something todo");
  let todo2 = Todo("something else todo");
  let todo3 = Todo("another thing todo");

  @todo1.completed(todo) {
    Console.writeln("Completed todo 1, " + todo.text);
  }

  todo2.complete();
  todo1.complete();
}
```


# Sample Programs
## Hello World
```
fn main(): void {
  Console.writeln("YOOOOOWWWW waddup world!");
}
```
## FizzBuzz
```
fn main(): int {
  for(mut i: int = 1; i <= 25; i++) {
    if (i % 3 == 0) Console.write("Fizz");
    if (i % 5 == 0) Console.write("Buzz");
    if (i % 3 != 0 && i % 5 != 0) Console.write("" + i);
    Console.writeln("");
  }
  
  return 7;
}
```
## Truth Machine
```
fn main() {
  let input = Console.readint();
  do Console.writeln("" + input);
  while (input == 1);
}
```
## Number guessing game
```
fn main() {
  mut life = 3;
  mut guess: int;
  mut end = false;
  let PUT_YOUR_RANDOM_NUMBER_HERE = 17;
  // and now guess it LMAO

  while(life > 0 && !end) {
    Console.writeln("Lives: " + life);
    Console.write("Guess: ");

    guess = Console.readint();

    if(guess != PUT_YOUR_RANDOM_NUMBER_HERE) {
      life--;
      guess > PUT_YOUR_RANDOM_NUMBER_HERE ? Console.writeln("Lower") : Console.writeln("Higher");
    }
    else { 
      Console.writeln("You won!");
      end = true;
    }

    if(life == 0) {
      Console.writeln("You lost...");
      end = true;
    }
  }
}
```

# Note
This competition was very fun and tought us a lot about developing languages and the challenges that come with it.
We want to thank repl.it for this challenge, as it was a great incentive for developing a language and trying some new things.
