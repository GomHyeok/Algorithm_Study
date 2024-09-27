#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int totalBlocks;
int blockCount[100010];
int canopyArea;

struct SegmentNode {
    int maxValue, leftIndex, rightIndex;
} segmentTree[400000];

SegmentNode combineNodes(SegmentNode leftNode, SegmentNode rightNode) {
    if (leftNode.maxValue > rightNode.maxValue) return leftNode;
    if (rightNode.maxValue > leftNode.maxValue) return rightNode;
    return SegmentNode{leftNode.maxValue, leftNode.leftIndex, rightNode.rightIndex};
}

void updateSegmentTree(int treeNode, int rangeStart, int rangeEnd, int targetPos, int newValue) {
    if (rangeStart == rangeEnd) {
        segmentTree[treeNode] = {newValue, targetPos, targetPos};
        return;
    }
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1, mid = (rangeStart + rangeEnd) / 2;
    if (targetPos <= mid) updateSegmentTree(leftChild, rangeStart, mid, targetPos, newValue);
    else updateSegmentTree(rightChild, mid + 1, rangeEnd, targetPos, newValue);
    segmentTree[treeNode] = combineNodes(segmentTree[leftChild], segmentTree[rightChild]);
}

SegmentNode querySegmentTree(int treeNode, int rangeStart, int rangeEnd, int queryStart, int queryEnd) {
    if (queryStart <= rangeStart && rangeEnd <= queryEnd) return segmentTree[treeNode];
    if (rangeEnd < queryStart || queryEnd < rangeStart) return {0, 0, 0};
    int leftChild = 2 * treeNode, rightChild = 2 * treeNode + 1, mid = (rangeStart + rangeEnd) / 2;
    return combineNodes(querySegmentTree(leftChild, rangeStart, mid, queryStart, queryEnd), querySegmentTree(rightChild, mid + 1, rangeEnd, queryStart, queryEnd));
}

void computeCanopyArea() {
    SegmentNode maxSegment = querySegmentTree(1, 1, totalBlocks, 1, totalBlocks);
    canopyArea = maxSegment.maxValue * (maxSegment.rightIndex - maxSegment.leftIndex + 1);
    int leftBoundary = maxSegment.leftIndex - 1, rightBoundary = maxSegment.rightIndex + 1;
    while (leftBoundary >= 1) {
        SegmentNode tempSegment = querySegmentTree(1, 1, totalBlocks, 1, leftBoundary);
        canopyArea += (leftBoundary - tempSegment.leftIndex + 1) * tempSegment.maxValue;
        leftBoundary = tempSegment.leftIndex - 1;
    }
    while (rightBoundary <= totalBlocks) {
        SegmentNode tempSegment = querySegmentTree(1, 1, totalBlocks, rightBoundary, totalBlocks);
        canopyArea += (tempSegment.rightIndex - rightBoundary + 1) * tempSegment.maxValue;
        rightBoundary = tempSegment.rightIndex + 1;
    }
}

void init(int N) {
    totalBlocks = N;
    canopyArea = 0;
    for (int i = 1; i <= totalBlocks; i++) updateSegmentTree(1, 1, totalBlocks, i, 0);
    memset(blockCount, 0, sizeof blockCount);
}

int stock(int blockLocation, int blockCountToAdd) {
    blockCount[blockLocation] += blockCountToAdd;
    updateSegmentTree(1, 1, totalBlocks, blockLocation, blockCount[blockLocation]);
    SegmentNode leftMaxNode = querySegmentTree(1, 1, totalBlocks, 1, blockLocation - 1);
    SegmentNode rightMaxNode = querySegmentTree(1, 1, totalBlocks, blockLocation + 1, totalBlocks);
    if (min(leftMaxNode.maxValue, rightMaxNode.maxValue) > blockCount[blockLocation]) return canopyArea;
    computeCanopyArea();
    return canopyArea;
}

int ship(int blockLocation, int blockCountToRemove) {
    int isUnchanged = 0;
    SegmentNode leftMaxNode = querySegmentTree(1, 1, totalBlocks, 1, blockLocation - 1);
    SegmentNode rightMaxNode = querySegmentTree(1, 1, totalBlocks, blockLocation + 1, totalBlocks);
    if (min(leftMaxNode.maxValue, rightMaxNode.maxValue) > blockCount[blockLocation]) isUnchanged = 1;
    blockCount[blockLocation] -= blockCountToRemove;
    updateSegmentTree(1, 1, totalBlocks, blockLocation, blockCount[blockLocation]);
    if (isUnchanged == 0) computeCanopyArea();
    return canopyArea;
}

int getHeight(int blockLocation) { 
    return blockCount[blockLocation];
}