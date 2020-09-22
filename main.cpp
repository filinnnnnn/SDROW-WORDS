//
//  main.cpp
//  SDROW
//
//  Created by user on 21.09.2020.
//  Copyright © 2020 user. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

enum FieldsType
{
    FT_WORD,
    FT_HINT,
    NUM_FIELDS
};
int score = 0;
std::string guess;
const int NUM_WORDS = 20;
const std::string WORDS[NUM_WORDS][NUM_FIELDS] =
{
    {
        "tiger",
        "a large Asian carnivorous mammal (Panthera tigris) of the cat family having a usually tawny coat transversely striped with black|"
    },
    {
        "turtle",
        "reptiles that have a toothless horny beak and a shell of bony dermal plates usually covered with horny shields enclosing the trunk"
    },
    {
        "pangolin",
        "Asian and African toothless mammals having the body covered dorsally with large imbricated horny scales"
    },
    {
        "frog",
        "have slender bodies with smooth moist skin and strong long hind legs with webbed feet"
    },
    {
        "axolotl",
        "live and breed in the larval form without metamorphosing"
    },
    {
        "sunfish",
        "bony fishes usually with a deep compressed body and metallic luster"
    },
    {
        "crocodile",
        "long-bodied, aquatic reptilesof tropical and subtropical waters that have a long, tapered, V-shaped snout"
    },
    {
        "rabit",
        "long-eared short-tailed lagomorph mammals with long hind legs"
    },
    {
        "snail",
        "gastropod mollusk when having an external enclosing spiral shell"
    },
    {
        "chameleon",
        "independently movable eyeballs, and unusual ability to change the color of the skin"
    },
    {
        "wolf",
        "active mostly at night, live and hunt in packs, and resemble the related dogs"
    },
    {
        "panther",
        "leopard of the black color phase"
    },
    {
        "leopard",
        "large strong cat that is adept at climbing and is usually tawny or buff with black spots arranged in rosettes"
    },
    {
        "fox",
        "dog family related to but smaller than wolves with shorter legs, more pointed muzzle, large erect ears, and long bushy tail"
    },
    {
        "elephant",
        "that has a snout elongated into a muscular trunk and two incisors in the upper jaw developed especially in the male into long ivory tusks"
    },
    {
        "pelican",
        "web-footed fish-eating birds with a very large bill and distensible gular pouch"
    },
    {
        "snake",
        "limbless scaled reptiles with a long tapering body and with salivary glands often modified to produce venom"
    },
    {
        "alpaca",
        "domesticated mammal from Peru that is probably descended from the vicuña, have got a long neck, and cutie face"
    },
    {
        "antelope",
        " have a slender lean build and usually horns directed upward and backward"
    },
    {
        "buffalo",
        "ahas short horns and heavy forequarters with a large muscular hump and that was formerly abundant on the central and western plains"
    },
};

void initGame()
{
    int choise = (rand() % NUM_WORDS);
    std::string theWord = WORDS[choise][FT_WORD];
    std::string theHint = WORDS[choise][FT_HINT];
    
    std::string mixedWord = theWord;
    int length = mixedWord.size();
    for (int i = 0; i < length; i++)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char tmp = mixedWord[index1];
        mixedWord[index1] = mixedWord[index2];
        mixedWord[index2] = tmp;
    }
    
    std::cout << "\n\t\tEnter 'hint' for a |HINT|TNIH|.";
    std::cout << "\n\t\tEnter 'quit' to quit the game.";
    std::cout << "\n\n\t\t\t\t\tThe \n\t\t\t\t|DROW|WORD| \n\t\t\t\tis: " << mixedWord;
    
    std::cout << "\n\nYou're guess: ";
    std::cin >> guess;
    while (guess != theWord && guess != "quit")
    {
        if (guess == "hint")
        {
            std::cout << "\t\t\t\t\t|HINT|TNIH|\n" << theHint << "\n\t\t\t\t\t|HINT|TNIH|";
        }
        else
        {
            std::cout << "\n\t\t|Sorry, i don't understand you :( |";
            std::cout << "\n\t\t|): uoy dnatsrednu t'nod i , yrroS|";
        }
        std::cout << "\n\nYou're guess: ";
        std::cin >> guess;
    }
    
    if (guess == theWord)
    {
        std::cout << "\n\t\tThat's it! You find your |DROW|WORD| !";
        score = score + mixedWord.size();
        std::cout << "\n\t\tYou're score: " << score;
        
        std::cout << "\n\n\t\t\t\t|PLAY AGAIN???|";
        std::cout << "\n\t\t\t\t|???NIAGA YALP|";
        std::cout << "\n\n\t\tEnter 'play' for new |SDROW|WORDS|.";
        std::cout << "\n\t\tEnter 'quit' to quit the game.";
    }
};

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    
    std::cout << "\t\t\t|!SDROW ot emocleW|";
    std::cout << "\n\t\t\t|Welcome to WORDS!|";
    std::cout << "\n\n\tMix the letters to make a |SDROW|WORDS|!";
    std::cout << "\n\n\t\tEnter 'play' for new |SDROW|WORDS|.";
    std::cout << "\n\t\tEnter 'quit' to quit the game.";
    
    while (guess != "quit")
    {
        std::cout << "\n\nYou're guess: ";
        std::cin >> guess;
        if (guess == "play")
        {
            initGame();
        }
        else if (guess == "quit")
        {
            std::cout << "\n\t\tThanks for plaing |SDROW|WORDS|!\n\n";
        }
        else
        {
            std::cout << "\n\t\t|Sorry, i don't understand you :( |";
            std::cout << "\n\t\t|): uoy dnatsrednu t'nod i , yrroS|";
        }
    }
    
    return 0;
}
