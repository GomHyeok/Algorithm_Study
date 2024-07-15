import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class UserSolution {
    
  static class NearPosition{
    int x;
    int y;
    int dis; // 거리
    int dir; // 방향

    NearPosition(int x, int y, int dis, int dir) {
      this.x = x;
      this.y = y;
      this.dis = dis; 
      this.dir = dir; 
    }
  };

  static class Path{
    int x;
    int y;
    int dir;

    Path(int x, int y, int dir) {
      this.x = x;
      this.y = y;
      this.dir = dir;
    }
  }

	private static final int UP	= 0;
	private static final int RIGHT = 1;
	private static final int DOWN = 2;
	private static final int LEFT = 3;
	
  private static int emptyY, emptyX;
  private static boolean isClear[][] = new boolean[5][5];

  private static int[] priorityDir = { UP, RIGHT, DOWN, LEFT }; // 방향 우선순위
    
  private static int dy[] = { -1, 0, 1, 0 };
  private static int dx[] = { 0, 1, 0, -1 };
	
	// Main API:
	//	  Solution.swap(int dir)
	
	public void solve(int[][] board, int[][] pattern, int callCntLimit) {
    // 빈칸의 위치
    for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (board[i][j] == 0) {
					emptyY = i;
					emptyX = j;
                    break;
				}
			}
		}
        
    // 맞혀야 하는 3*3 구역 중 좌상단부터 순서대로 퍼즐 맞추기
    for(int i = 1; i <= 3; i++) {
      for(int j = 1; j <= 3; j++) {
        // 이미 정답이면 if문 과정 패스
        if(board[i][j] != pattern[i - 1][j - 1]) {
          // 해당 자리에 놓여야 하는 퍼즐 조각 중 가장 가까운 정답의 위치 가져오기
          // 해당 자리의 상하좌우에서 가까운
          NearPosition min = new NearPosition(6, 6, 50, -1);

          Queue<NearPosition> queue = new LinkedList<NearPosition>();
          boolean[][] visited = new boolean[5][5];
          queue.offer(new NearPosition(j, i, 0, -1));

          while(!queue.isEmpty()) {
            NearPosition current = queue.poll();

            for(int k = 0; k < 4; k++) {
              int moveX = current.x + dx[k];
              int moveY = current.y + dy[k];

              // 범위를 벗어났거나, 이미 완성된 자리 또는 이미 지나간 자리인 경우 패스
              if(moveX < 0 || moveX >= 5 || moveY < 0 || moveY >= 5 || isClear[moveY][moveX] || visited[moveY][moveX]) continue;
              //System.out.println("Test: " + moveY + ", " + moveX);
              // 지나감 체크
              visited[moveY][moveX] = true;
              NearPosition movePuzzle = new NearPosition(moveX, moveY, current.dis + 1, k);

              // 정답 퍼즐이라면?
              if(board[moveY][moveX] == pattern[i - 1][j - 1]) {
                min = movePuzzle;
                // 뒤에 오는 것들은 더 가까울 수 없으므로 반복 종료
                queue.clear();
                break;
              }

              // 정답이 아닌 경우
              queue.offer(movePuzzle);
            }
          }
            isClear[min.x][min.y] = true;
          // 가까운 정답을 현 위치로 이동
          moveSuccess(board, pattern, min.x, min.y, j, i);
          isClear[min.x][min.y] = false;
          
          //System.out.println("clear: " + i + ", " + j);
        }
            
        // 맞춘 퍼즐 자리 표시
        isClear[i][j] = true;
      }
    }
	}

  // 정답을 원하는 위치로 이동 - 경로 구하기
  public static void moveSuccess(int[][] board, int[][] pattern, int currentX, int currentY, int goalX, int goalY) {
    // 정답 길 찾기
    ArrayList<Path> successPath = new ArrayList<Path>();
    successPath.add(new Path(currentX, currentY, -1));

    Queue<ArrayList<Path>> queue = new LinkedList<ArrayList<Path>>();
    boolean[][] visited = new boolean[5][5];
    queue.offer(successPath);

    while (!queue.isEmpty()) {
      ArrayList<Path> curPath = queue.poll();
      Path curPosition = curPath.get(curPath.size() - 1);

      for(int i = 0; i < 4; i++) {
        int moveX = curPosition.x + dx[i];
        int moveY = curPosition.y + dy[i];

        // 범위를 벗어났거나, 이미 완성된 자리 또는 이미 방문한 자리인 경우 패스
        if(moveX < 0 || moveX >= 5 || moveY < 0 || moveY >= 5 || isClear[moveY][moveX] || visited[moveY][moveX]) continue;

        visited[moveY][moveX] = true;
        ArrayList<Path> movePath = (ArrayList<Path>) curPath.clone();
        movePath.add(new Path(moveX, moveY, (i+2)%4)); //내가 이동한 경로의 반대 = 빈블록 이동 경로

        // 도착점
        if(moveX == goalX && moveY == goalY) {
          successPath = movePath;
          
          queue.clear();
          break;
        }

        queue.add(movePath);
      }
    }

    

    // // 바로 옆에 있으면 = 이동 경로가 한칸 (현위치 포함하면 2칸)
    // if(successPath.size() == 2) {
    //   int oneX = successPath.get(0).x;
    //   int twoX = successPath.get(1).x;

    //   int oneY = successPath.get(0).y;
    //   int twoY = successPath.get(1).y;

    //   successPath.remove(1);
      
    //   // 바깥 라인으로
    //   // 세로가 같으면
    //   if(oneX == twoX) {
    //     if(oneX == 1) {
    //       successPath.add(new Path(0, oneY, RIGHT));
    //       int dir = (oneY - twoY > 0) ? UP : DOWN;
    //       successPath.add(new Path(0, twoY, dir));
    //       successPath.add(new Path(twoX, twoY, LEFT));
    //     }
    //     else {
    //       successPath.add(new Path(oneX + 1, oneY, LEFT));
    //       int dir = (oneY - twoY > 0) ? UP : DOWN;
    //       successPath.add(new Path(oneX + 1, twoY, dir));
    //       successPath.add(new Path(twoX, twoY, RIGHT));
    //     }
    //   }

    //   // 가로가 같으면
    //   else if(oneY == twoY) {
    //     if(oneY == 1) {
    //       successPath.add(new Path(oneX, 0, DOWN));
    //       int dir = (oneX - twoX > 0) ? LEFT : RIGHT;
    //       successPath.add(new Path(twoX, 0, dir));
    //       successPath.add(new Path(twoX, twoY, UP));
    //     }
    //     else {
    //       successPath.add(new Path(oneX, oneY + 1, UP));
    //       int dir = (oneX - twoX > 0) ? RIGHT : LEFT;
    //       successPath.add(new Path(twoX, oneY + 1, dir));
    //       successPath.add(new Path(twoX, twoY, DOWN));
    //     }
    //   }
    // }
    
    System.out.println("empty block 시작위치 : " + emptyY + ", " + emptyX + " | ");
    System.out.println("움직이고자 하는 block의 이동경로");
    for(int i = 0; i < successPath.size(); i++) {
      System.out.print(successPath.get(i).y +  ", " + successPath.get(i).x + ", " + successPath.get(i).dir + " / ");
    }
    System.out.println();
    
    successPath.remove(0);
    NearPosition checkPosition = new NearPosition(-1, -1, 0, 0);
    while (successPath.size() > 0) {
    //   // 이미 정답이 됐으면 멈추기
    //   if(board[goalY][goalX] == pattern[goalY - 1][goalX - 1]) break;
      
    //   if(checkPosition.x != -1) {
    //     if(checkPosition.dis > 1) {
    //       isClear[checkPosition.y][checkPosition.x] = false;
    //       checkPosition = new NearPosition(-1, -1, 0, 0);
    //     }
    //     else checkPosition.dis++;
    //   }

      // 공백을 이동
      moveEmpty(board, successPath.get(0).x, successPath.get(0).y);

      // 공백하고 자리 바꾸기
      Solution.swap(successPath.get(0).dir);
      swap(board, successPath.get(0).dir);

    //   if(checkPosition.x != -1) isClear[checkPosition.y][checkPosition.x] = false;
    //   checkPosition = new NearPosition(successPath.get(0).x, successPath.get(0).y, 0, 0);
    //   isClear[successPath.get(0).y][successPath.get(0).x] = true;

      successPath.remove(0);
    }
    
    // if(checkPosition.x != -1) isClear[checkPosition.y][checkPosition.x] = false;
  }
    
  // 공백을 원하는 위치로 이동
  public static void moveEmpty(int[][] board, int goalX, int goalY) {
    // System.out.println(goalY + ", " + goalX);
    boolean[][] visited = new boolean[5][5];

    visited[emptyY][emptyX] = true;
    // 상하좌우 방향이 막혀있었던 것을 기억
    boolean[] blockDir = new boolean[4];
    while (emptyX != goalX || emptyY != goalY) {
    //   setPriority(emptyX, emptyY, goalX, goalY);

      for(int i = 0; i < 4; i++) {
        // int dir = priorityDir[i];
        // if(emptyY == goalY) dir = priorityDir[(i + 1) % 4];

        int moveX = emptyX + dx[i];
        int moveY = emptyY + dy[i];

        // 범위를 벗어났거나, 이미 완성된 자리 또는 이미 방문한 자리인 경우 패스 + 이전에 막혀있던 방향이면
        if(moveX < 0 || moveX >= 5 || moveY < 0 || moveY >= 5 || isClear[moveY][moveX] || visited[moveY][moveX] || blockDir[i]) {
          blockDir[i] = true;
          continue;
        }
        
        visited[moveY][moveX] = true;

        // 방향 전환되면 막혔던 거 빼기
        if(blockDir[(i+1) % 4]) blockDir[(i+1) % 4] = false;
        if(blockDir[(i+3) % 4]) blockDir[(i+3) % 4] = false;

        // 공백 이동
        Solution.swap(i);
        swap(board, i);

        break;
      }
    }
  }

  // copy board도 같이 swap
  private static boolean swap(int[][] board, int dir) {
		if (dir < UP || dir > LEFT) {
			return false;
		}

		int newY = emptyY + dy[dir];
		int newX = emptyX + dx[dir];

		if (newY < 0 || newY >= 5 || newX < 0 || newX >= 5) {
			return false;
		}

		board[emptyY][emptyX] = board[newY][newX];
		board[newY][newX] = 0;
		emptyY = newY;
		emptyX = newX;
		
		return true;
	}

  // 방향 우선순위
  private static void setPriority(int currentX, int currentY, int goalX, int goalY) {
    priorityDir[0] = UP;
    priorityDir[1] = RIGHT;
    priorityDir[2] = DOWN;
    priorityDir[3] = LEFT;

    if(goalY > currentY) {
      priorityDir[0] = DOWN;
      priorityDir[2] = UP;
    }
    if(goalX < currentX) {
      priorityDir[1] = LEFT;
      priorityDir[3] = RIGHT;
    }
  }
}
