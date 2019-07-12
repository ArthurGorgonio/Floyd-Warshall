#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 *
 *       Filename:  floyd-warshall.c
 *
 *    Description:  Perform the Floyd-Warshall algorithm to solve the all-pairs
 *        shortest-paths problem on a directed graph for all matrix. We assume
 *        all the input file is parsed using Unix operator '<' when this output
 *        file is executed.
 *
 *        Version:  1.0
 *        Created:  2019 Jun 11 12:00 -0300
 *    Last Edited:  2019 Jun 11 12:00 -0300
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Arthur Gorgônio, gorgonioarthur@gmail.com
 *   Organization:
 *
 * ============================================================================
 */

/*
 * ===  FUNCTION  =============================================================
 *           Name:  floydWarshall 
 *    Description:  Perform the Floyd-Warshall algorithm to solve the all-pairs
 *        shortest-paths problem on a directed graph.
 *
 *         Params:
 *         graph => A matrix with the weigths of the edges.
 *             v => The number of the vertex (length) in the graph.
 *
 *         Return:  int
 *             0 => In the parsed graph has nagative cycles.
 *             1 => In the parsed graph does not has negative cycles.
 * ============================================================================
*/
int floydWarshall(float **graph, int v) {
  int i, j, k;
  for(i = 0; i < v; i++) {
    for(j = 0; j < v; j++) {
      for(k = 0; k < v; k++) {
        if (graph[i][j] > (graph[i][k] + graph[k][j])) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
  for (i = 0; i < v; i++) {
    if (graph[i][i] < 0) {
      return 0;
    }
  }
  return 1;
}

/*
 * ===  FUNCTION  =============================================================
 *           Name:  main 
 *    Description:  The main function, we assume all the input file is parsed
 *        using Unix operator '<' when this output file is executed.
 *
 *         Params:
 *
 *         Return:  int
 *             0 => No erros in this algorithm.
 *             1 => A error, in graph has negative cycles.
 *             2 => File don't exists
 * ============================================================================
*/
int main() {
  int v, i, j;
  scanf("%d", &v);
  FILE *fp;
  fp = fopen("output.txt", "w");
  if (fp != NULL) {
    float **graph = (float **) malloc(v * sizeof(float *));
    for(i = 0; i < v; i++) {
      graph[i] = (float *) malloc(v * sizeof(float));
    }
    for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
        scanf("%g", &graph[i][j]);
      }
    }
    int fw = floydWarshall(graph, v);
    for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
        fprintf(fp, "%g\t", graph[i][j]);
      }
      fprintf(fp,"\n");
    }
    free(graph);
    fclose(fp);
    if (fw) {
      printf("No negative cycles!\n");
      return 0;
    } else {
      printf("Negative cycles found!\n");
      return 1;
    }
  } else {
    printf("Can not open file!\n");
    return 2;
  }
}
