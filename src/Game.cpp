#include "Game.h"
#include "Item.h"
#include "Colors.h"
#include "SantaClauss.h"
#include "ElfArmy.h"
#include "Elf.h"
#include <ctime>
#include <iostream>

Game::Game()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Game] Constructor\n";
#endif
}

Game::~Game()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Game] Destructor\n";
#endif
}

void Game::run()
{

    std::cout << BOLD << BLUE << "\n=== Game Begins ===\n" << RESET;

    episode1(); 
    episode2(); 
    episode3(); 
    episode4(); 
    episode5(); 


    std::cout << BOLD << BLUE << "=== The End ===\n" << RESET;
}

void Game::episode1()
{
    std::cout << BOLD << GREEN << "\n=== EPISODE 1 ===\n" << RESET;

#ifdef DEBUG
    std::cout << "[DEBUG][Game] Display player statistics...\n";
#endif

    player.showStats();

#ifdef DEBUG
    std::cout << "[DEBUG][Game] Create a sword...\n";
#endif

    Item sword("Knight sword", 15, 50);

#ifdef DEBUG
    std::cout << "[DEBUG][Game] Add the sword to the inventory...\n";
#endif

    player.getInventory().add(sword);

    player.getInventory().show();
}

//

void Game::episode2()
{
    std::cout << BOLD << GREEN
    << "\n=== EPISODE 2 ===\n"
    << RESET;


    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << CYAN << "\n=== Creating Santa using different constructors ===\n" << RESET;

    SantaClauss m1;                                  
    SantaClauss m2("Santa CLauss Warrior", 150, 25);       
    SantaClauss m3(m2);                                  
    SantaClauss m4(2);                                   
    SantaClauss m5(true, 130);                           

    m1.showStats();
    m2.showStats();
    m3.showStats();
    m4.showStats();
    m5.showStats();
    
    std::cout << CYAN << "\n=== Creating Elf using different constructors ===\n" << RESET;

    Elf e1;                                                
    Elf e2("Elf guardian", 75, ElfClassType::Warrior);     
    Elf e3(e2);                                            
    Elf e4 = Elf::createWarrior("Elf Warrior");          
    Elf e5 = Elf::createMage("Elf mage");           
    Elf e6(ElfClassType::Archer);                          

    e1.showStats();
    e2.showStats();
    e3.showStats();
    e4.showStats();
    e5.showStats();
    e6.showStats();


    std::cout << CYAN << "\n===  Creating Elf Army using different constructors ===\n" << RESET;

    ElfArmy ea1;                                            
    ElfArmy ea2(3, ElfClassType::Mage);                     
    ElfArmy ea3({"Elfik", "Zefir", "Grom"}, ElfClassType::Warrior); 
    ElfArmy ea4(ea2);                                       
    ElfArmy ea5; ea5.summonRandom(4);               

    ea1.show();
    ea2.show();
    ea3.show();
    ea4.show();
    ea5.show();




    // std::cout << "\n=== 4. Tworzenie armii Mikołajów różnymi konstruktorami ===\n";

    // SantaArmy sa1;                   // pusta
    // SantaArmy sa2(3);                // zwykła armia 3
    // SantaArmy sa3(2, true);          // elitarna armia
    // SantaArmy sa4(sa3);              // kopiująca
    // SantaArmy sa5; sa5.summonElite(3); // summon

    // std::cout << "\n[PUSTA]"; sa1.show();
    // std::cout << "\n[3 ZWYKŁYCH]"; sa2.show();
    // std::cout << "\n[ELITARNA]"; sa3.show();
    // std::cout << "\n[KOPIA ELITARNEJ]"; sa4.show();
    // std::cout << "\n[SAMMONE ELITARNYCH]"; sa5.show();



    // std::cout << "\n=====================================================\n";
    // std::cout << "                   WALKI TESTOWE                     \n";
    // std::cout << "=====================================================\n";

    // //
    // // 5a) WALKA 1 vs 1
    // //
    // std::cout << "\n--- WALKA 1 vs 1: Mikołaj (delegujący) vs Elf (losowy) ---\n";

    // SantaClauss fighterSanta = m4;   // delegujący konstruktor Mikołaja
    // Elf fighterElf = e6;             // losowy łucznik

    // std::cout << "\n> PRZED WALKĄ:\n";
    // fighterSanta.showStats();
    // fighterElf.showStats();

    // int round = 1;
    // while (fighterSanta.isAlive() && fighterElf.isAlive())
    // {
    //     std::cout << "\n[Runda " << round << "]\n";

    //     int sHit = fighterSanta.getBaseDamage() + std::rand() % 10;
    //     int eHit = fighterElf.getBaseDamage() + std::rand() % 8;

    //     std::cout << "Mikołaj atakuje za " << sHit << "\n";
    //     fighterElf.takeDamage(sHit);

    //     if (!fighterElf.isAlive())
    //         break;

    //     std::cout << "Elf uderza za " << eHit << "\n";
    //     fighterSanta.takeDamage(eHit);

    //     round++;
    // }

    // std::cout << "\n> WYNIK WALKI 1v1:\n";
    // if (fighterSanta.isAlive())
    //     std::cout << "Mikołaj zwycięża! 🎅\n";
    // else
    //     std::cout << "Elf zwycięża! 🧝\n";



    // //
    // // 5b) WALKA ARMIA vs ARMIA
    // //
    // std::cout << "\n=====================================================\n";
    // std::cout << "                 WALKA ARMIA vs ARMIA                \n";
    // std::cout << "=====================================================\n";

    // // wybierz armie utworzone różnymi konstruktorami:
    // SantaArmy battleSanta = sa3;   // elitarna armia (konstruktor parametr+elite)
    // ElfArmy battleElves = ea3;     // imienna armia (konstruktor listowy)

    // battleSanta.show();
    // battleElves.show();

    // battleArmies(battleSanta, battleElves);

}



void Game::episode3()
{
    

}

void Game::episode4()
{
    

}

void Game::episode5()
{
    

}
