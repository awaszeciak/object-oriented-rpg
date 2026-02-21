#include "questFunctions.h"
#include <iostream>
#include "Colors.h"

Reward miningGold(const Quest& quest) {
    
    std::cout << YELLOW << "Mining gold in the mountains...\n";
    std::cout << "Quest: " << quest.getName() << RESET << "\n";

    quest.incrementExecution();

    int goldEarned = 100;
    return Reward(goldEarned);
}

Reward collectSnow(const Quest& quest) {

    std::cout << BLUE << "Collecting fresh snow for Santa...\n";
    std::cout << "Quest: " << quest.getName()  << RESET << "\n";

    quest.incrementExecution();

    Item snowItem("Magic Snowball", 10, 5);
    return Reward(snowItem);

}

Reward huntReindeer(const Quest& quest) {

    std::cout << GREEN << "Hunting reindeer in the frozen  forest... \n";
    std::cout << "Quest: " << quest.getName() << RESET << "\n";

    quest.incrementExecution();

    SantaClauss companion(2);
    return Reward(companion);
}
