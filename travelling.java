import java.util.Scanner;
public class travelling {
    static int FHamiltonCycle(int [][] distance,boolean[] visitCity, int currPos, int cities,int count,int cost,int hamiltonCycle){
        if(count==cities && distance[currPos][0]>0){
            hamiltonCycle=Math.min(hamiltonCycle,cost+distance[currPos][0]);
            return hamiltonCycle;
        
        }
        for(int i=0;i<cities;i++){
            if(visitCity[i]==false && distance[currPos][i]>0){
                visitCity[i]=true;
                hamiltonCycle=FHamiltonCycle(distance, visitCity, i, cities, count+1, cost+distance[currPos][i], hamiltonCycle);
                visitCity[i]=false;
            }
        }
        return hamiltonCycle;
    }
    public static void main(String[] args){
        int cities;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter total number of cities ");
        cities = sc.nextInt();
        int distance[][] = new int[cities][cities];
    
        for (int i = 0; i < cities; i++) {
            for (int j = 0; j < cities; j++) {
                System.out.println("Distance from " + (i + 1) + " to " + (j + 1) + ":");
                distance[i][j] = sc.nextInt();
            }
        }
 
        boolean[] visitCity = new boolean[cities];
 
        visitCity[0] = true;
 
        int hamiltonianCycle = 999;
 
        hamiltonianCycle = FHamiltonCycle(distance, visitCity, 0, cities, 1, 0, hamiltonianCycle);
 
        System.out.println("Cost of the Path taken by TSP: " + hamiltonianCycle);
    }
}
