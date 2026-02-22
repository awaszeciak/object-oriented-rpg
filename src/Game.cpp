#include "Game.h"
#include "Item.h"
#include "Colors.h"
#include "SantaClauss.h"
#include "SantaArmy.h"
#include "ElfArmy.h"
#include "../actionlib/include/Action.h"
#include "../actionlib/include/ActionQueue.h"
#include "../actionlib/include/Hero.h"
#include "battleArmies.h"
#include "Quest.h"
#include "QuestTimer.h"
#include "Reward.h"
#include "questFunctions.h"
#include "Elf.h"
#include "../questlib/include/Reward_v2.h"
#include "../questlib/include/Quest_v2.h"
#include "../questlib/include/questFunctions_v2.h"
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>

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



void Game::episode2()
{
    std::cout << BOLD << GREEN
    << "\n=== EPISODE 2 ===\n"
    << RESET;


    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << CYAN << "\n=== Creating Santa using different constructors ===\n" << RESET;

    SantaClauss m1;                                  
    SantaClauss m2("Santa Clauss Warrior", 150, 25);       
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




    std::cout << CYAN << "\n=== Creating Santa Army using different constructors ===\n" << RESET;

    SantaArmy sa1;                   
    SantaArmy sa2(3);                
    SantaArmy sa3(2, true);          
    SantaArmy sa4(sa3);
    SantaArmy sa5; sa5.summonElite(3); 

    sa1.show();
    sa2.show();
    sa3.show();
    sa4.show();
    sa5.show();



    std::cout << CYAN << "\n=== Test battles ===\n" << RESET;
    
    std::cout << MAGENTA << "\n=== 1 vs 1 BATTLE: Santa (delegating constructor) vs Elf (random) ===\n" << RESET;


    SantaClauss fighterSanta = m4;  
    Elf fighterElf = e6;             

    std::cout << YELLOW <<"\n> BEFORE BATTLE:\n" << RESET;
    fighterSanta.showStats();
    fighterElf.showStats();

    int round = 1;
    while (fighterSanta.isAlive() && fighterElf.isAlive())
    {
        std::cout << YELLOW <<"\n[Round " << round << "]\n" << RESET;

        int sHit = fighterSanta.getBaseDamage() + std::rand() % 10;
        int eHit = fighterElf.getBaseDamage() + std::rand() % 8;

        std::cout << "Santa attacks for " << sHit << "\n";
        fighterElf.takeDamage(sHit);

        if (!fighterElf.isAlive())
            break;

        std::cout << "Elf hits for " << eHit << "\n";
        fighterSanta.takeDamage(eHit);

        round++;
    }

    std::cout << GREEN <<  "\n> 1vs1 BATTLE RESULT\n" << RESET;
    if (fighterSanta.isAlive())
        std::cout << "Santa wins!\n";
    else
        std::cout << "Elf wins!\n";



    std::cout << MAGENTA << "\n=== ARMY vs ARMY BATTLE: SantaArmy (Elite) vs ElfArmy (List) ===\n" << RESET;

    SantaArmy battleSanta = sa3; 
    ElfArmy battleElves = ea3;  

    std::cout << YELLOW <<"\n> BEFORE BATTLE:\n" << RESET;
    battleSanta.show();
    battleElves.show();

    battleArmies(battleSanta, battleElves);

}

void Game::episode3(){

    std::cout << BOLD << GREEN
    << "\n=== EPISODE 3 ===\n"
    << RESET;

    Character goldMiner("GoldMinder", 100, 5);
    Character snowCollector(std::string("SnowCollector"), 90, 3);
    Character reindeerHunter("ReindeerHunter", 110, 6);

    goldMiner.showStats();
    snowCollector.showStats();
    reindeerHunter.showStats();


    Quest q1 = "Mining Gold";
    Quest q2(std::string("Collect Snow"));
    Quest q3("Hunt Reindeer");

    QuestTimer timer1(q1.getDuration());
    QuestTimer timer2(q2.getDuration());
    QuestTimer timer3(q3.getDuration());


    std::cout << "\n" << GREEN << "=== Starting quests! ===\n" << "\n" << RESET;


    while (static_cast<bool>(timer1)) {
        miningGold(q1);
        timer1.tick();
    }

    Reward r1 = miningGold(q1);
    int gold = static_cast<int>(r1);

    std::cout << YELLOW << "goldMiner has earned: " << gold << "\n" << RESET;

    while (static_cast<bool>(timer2)) {
        collectSnow(q2);
        timer2.tick();
    }

    Reward r2 = collectSnow(q2);
    Item snowItem = static_cast<Item>(r2);

    std::cout << CYAN << "SnowCollector has earned item:  " << snowItem.getName() << RESET << "\n";


    while (static_cast<bool>(timer3)) {
        huntReindeer(q3);
        timer3.tick();
    }

    Reward r3 = huntReindeer(q3);
    SantaClauss guardian = static_cast<SantaClauss>(r3);


    std::cout << GREEN << "ReindeerHunter has earned guardian of the reward\n" << RESET;
    guardian.showStats();

}

void Game::episode4()
{
    using RPG::Quests::Quest_v2;
    using RPG::Quests::SubQuest_v2;
    using RPG::Rewards::Reward_v2;
    using RPG::Rewards::GoldAmount_v2;
    using RPG::Rewards::ExpAmount_v2;

    std::cout << BOLD << GREEN << "\n === EPISODE 4 === \n" << RESET;

    Quest_v2 q1 = "Mining Gold";
    q1.addSubQuest(SubQuest_v2("Find Vein"));  
    q1.addSubQuest(SubQuest_v2(std::string("Mine Ore"), 4));
    q1.addSubQuest(SubQuest_v2(std::string("Transport"), 2));

    Reward_v2 r = Reward_v2(ExpAmount_v2(0));

    while (!q1.isCompleted()) {
        r = RPG::Tasks::miningGold_v2(q1);
    }

    GoldAmount_v2 goldObj = static_cast<GoldAmount_v2>(r);
    int gold = static_cast<int>(goldObj);
    std::cout << MAGENTA << "Reward from MiningGold: gold=" << gold << RESET <<"\n";

    Quest_v2 q2(std::string("Collect Snow"));
    q2.addSubQuest(SubQuest_v2("Go Outside"));
    q2.addSubQuest(SubQuest_v2(std::string("Fill Pouch"), 3));

    Reward_v2 r2 = Reward_v2(ExpAmount_v2(0));
    while (!q2.isCompleted()) {
        r2 = RPG::Tasks::collectSnow_v2(q2);
    }

    ExpAmount_v2 expObj = static_cast<ExpAmount_v2>(r2);
    int exp = static_cast<int>(expObj);
    Item it = static_cast<Item>(r2);

    std::cout << MAGENTA << "Reward from CollectSnow: exp=" << exp
              << ", item=" << it.getName() << RESET << "\n";
}

void Game::episode5()
{
    using RPG::Actions::Hero;
    using RPG::Actions::Action;
    using RPG::Actions::ActionQueue;

    std::cout << BOLD << GREEN << "\n === EPISODE 5 === \n" << RESET;

    
    Hero explorer("Explorer", 120, 60);
    Hero guardian("Guardian", 140, 40);

    std::cout << "\n[Start]\n";
    explorer.show();
    guardian.show();

    Action strike("Strike", explorer, guardian, 10);
    Action heal("HealPulse", Action::Heal, explorer, 6); 
    Action rest("Rest", Action::Rest, explorer, 8);  

    std::cout << MAGENTA << "\n[First actions]\n" << RESET;
    std::cout << strike << "\n";
    std::cout << heal << "\n";
    std::cout << rest << "\n";


     ++strike;     
    rest++;      
    --heal;       
    

    std::cout << MAGENTA << "\n[After ++/--]\n" << RESET;
    std::cout << strike << "\n";
    std::cout << heal << "\n";
    std::cout << rest << "\n";

    int pwr = static_cast<int>(strike);
    std::cout << YELLOW << "\nPower of strike (static_cast<int>): " << pwr << "\n" <<RESET;

    std::stringstream ss;
    ss << "15 Thunder"; 
    ss >> strike;

    std::cout << MAGENTA << "\n[After >>]\n" << RESET;
    std::cout << strike << "\n";

    ActionQueue q;

    q.push(strike);

    q.push([refStrike = std::ref(strike)]() {
        refStrike.get()();
    });

    q.push([&]() {
        std::cout << "[Lambda] Status:\n";
        explorer.show();
        guardian.show();
    });

    q.push(heal);
    q.push(rest);

    std::cout << "\nSize=" << q.size() << "\n";
    std::cout << "\n[RUN]\n";
    q(); 

    std::cout << "\n[After]\n";
    explorer.show();
    guardian.show();

    std::cout << MAGENTA <<"\n[Original strike after run]\n"<<RESET;
    std::cout << strike << "\n";
}
