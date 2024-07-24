#include <iostream>
#include <cmath>

void countNodes(int n, int &twoChildren, int &oneChild) {
    int height = std::floor(std::log2(n));
    int lastLevelNodes = n - (std::pow(2, height) - 1);
    int totalNodesExceptLastLevel = std::pow(2, height) - 1;

    twoChildren = (totalNodesExceptLastLevel - 1) + (lastLevelNodes / 2);
    oneChild = lastLevelNodes % 2;
}

int main() {
    int n = 8; // 예시로 8개의 노드
    int twoChildren = 0, oneChild = 0;

    countNodes(11, twoChildren, oneChild);

    std::cout << "자식 노드가 2개인 노드 수: " << twoChildren << std::endl;
    std::cout << "자식 노드가 1개인 노드 수: " << oneChild << std::endl;

    return 0;
}
