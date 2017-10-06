//k-means clustering
//author : insyi
//last updated : 5/10/2017 

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

const int object_total = 7000;
const int features_total = 200;
const int iteration = 100;

int main(){

    int k = 15;
    int belongs_to[object_total];
    int prev_belongs_to[object_total];
    float centroids[k][features_total];
    int cluster_objects[object_total];
    float data[object_total][features_total];


    //retrieve objects from textfile
    FILE *file= fopen("/home/insyirah/Desktop/C101-70100-P.txt","r");

      int row=0;
 
      while ((!feof(file)) && (row<7000)){
          fscanf(file, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", 
          &data[row][0], &data[row][1], &data[row][2], &data[row][3], &data[row][4], &data[row][5], &data[row][6], &data[row][7], &data[row][8], &data[row][9], &data[row][10], &data[row][11], &data[row][12], &data[row][13], &data[row][14], &data[row][15], &data[row][16], &data[row][17], &data[row][18], &data[row][19], &data[row][20], &data[row][21], &data[row][22], &data[row][23], &data[row][24], &data[row][25], &data[row][26], &data[row][27], &data[row][28], &data[row][29], &data[row][30], &data[row][31], &data[row][32], &data[row][33], &data[row][34], &data[row][35], &data[row][36], &data[row][37], &data[row][38], &data[row][39],
          &data[row][40], &data[row][41], &data[row][42], &data[row][43], &data[row][44], &data[row][45], &data[row][46], &data[row][47], &data[row][48], &data[row][49], &data[row][50], &data[row][51], &data[row][52], &data[row][53], &data[row][54], &data[row][55], &data[row][56], &data[row][57], &data[row][58], &data[row][59], &data[row][60], &data[row][61], &data[row][62], &data[row][63], &data[row][64], &data[row][65], &data[row][66], &data[row][67], &data[row][68], &data[row][69], &data[row][70], &data[row][71], &data[row][72], &data[row][73], &data[row][74], &data[row][75], &data[row][76], &data[row][77], &data[row][78], &data[row][79],
          &data[row][80], &data[row][81], &data[row][82], &data[row][83], &data[row][84], &data[row][85], &data[row][86], &data[row][87], &data[row][88], &data[row][89], &data[row][90], &data[row][91], &data[row][92], &data[row][93], &data[row][94], &data[row][95], &data[row][96], &data[row][97], &data[row][98], &data[row][99], &data[row][100], &data[row][101], &data[row][102], &data[row][103], &data[row][104], &data[row][105], &data[row][106], &data[row][107], &data[row][108], &data[row][109], &data[row][110], &data[row][111], &data[row][112], &data[row][113], &data[row][114], &data[row][115], &data[row][116], &data[row][117], &data[row][118], 
          &data[row][119], &data[row][120], &data[row][121], &data[row][122], &data[row][123], &data[row][124], &data[row][125], &data[row][126], &data[row][127], &data[row][128], &data[row][129], &data[row][130], &data[row][131], &data[row][132], &data[row][133], &data[row][134], &data[row][135], &data[row][136], &data[row][137], &data[row][138], &data[row][139], &data[row][140], &data[row][141], &data[row][142], &data[row][143], &data[row][144], &data[row][145], &data[row][146], &data[row][147], &data[row][148], &data[row][149], &data[row][150], &data[row][151], &data[row][152], &data[row][153], &data[row][154], &data[row][155], &data[row][156], 
          &data[row][157], &data[row][158], &data[row][159], &data[row][160], &data[row][161], &data[row][162], &data[row][163], &data[row][164], &data[row][165], &data[row][166], &data[row][167], &data[row][168], &data[row][169], &data[row][170], &data[row][171], &data[row][172], &data[row][173], &data[row][174], &data[row][175], &data[row][176], &data[row][177], &data[row][178], &data[row][179], &data[row][180], &data[row][181], &data[row][182], &data[row][183], &data[row][184], &data[row][185], &data[row][186], &data[row][187], &data[row][188], &data[row][189], &data[row][190], &data[row][191], &data[row][192], &data[row][193], &data[row][194], 
          &data[row][195], &data[row][196], &data[row][197], &data[row][198], &data[row][199]);    

          row++;
      }    

      //initialize centroids (k : number of centroid)
    for (int a=0; a<k; a++){
        for (int b =0; b<features_total; b++){
            centroids[a][b] = data[a*10][b*10];
            //printf("%f ,", centroids [a][b]);
        }
        printf("\n");
    }

    int cluster_size[k];

    //find the real position of centroids
    for (int i=0; i<iteration; i++){

        for (int y = 0; y < k ; y++)
        {
            cluster_size[y] = 0;
        }


        //do until no changes are needed
        int change = 0; //False

        for (int j=0; j<object_total; j++){


            float distance =0.0, min_distance =0.0;
            float total_distance;
            int index=1;
            belongs_to[j] = 0;

            //set initial minimum distance

            for (int l=0; l<features_total; l++){
                min_distance += ((data[j][l]-centroids[0][l]) * (data[j][l]-centroids[0][l]));
            }

            //update minimum distance
            for (int m=1; m<k; m++){
                
                distance = 0.0;


                for (int n=0; n<features_total; n++){
                    distance += ((data[j][n]-centroids[m][n]) * (data[j][n]-centroids[m][n]));
                    //printf("distance : %f \n", distance);
                }

                if (distance<min_distance){
                    
                    min_distance = distance;
                    index = m+1;
                }

            }

            cluster_size[index] += 1;
            belongs_to[j] = index;

            //check for any cluster changes
            if (prev_belongs_to[j] != belongs_to[j]){
                change += 1; //True

            }

            prev_belongs_to[j] = belongs_to[j];
        }


        int total_objects = 0;

        printf("\n\n Iteration %d\n", i+1);

        for (int g=0; g<k; g++){
                
            printf("Cluster %d size is %d\n", g+1 , cluster_size[g]);
            //total_objects += cluster_size[g];

        }

        //calculate average deviation/errors
        float average_deviation = 0.0; 


        for (int b=0; b<k; b++){
            for (int j=0; j<object_total; j++){
                if (belongs_to[j] == b){
                    for (int l=0; l<features_total; l++){
                        average_deviation += (abs(data[j][l]-centroids[b][l]) * abs(data[j][l]-centroids[b][l]));

                        
                    }

                }

            }    
            //printf("%f \n", average_deviation );
        }

        printf("Average deviation : %f\n\n", average_deviation/10000000);

        //check if the iteration is final.
        if (change == 0){
            break;
        }else{

            //update centroids' mean
            float new_centroids[k][features_total];

            for (int c=0; c<k; c++){
                for (int d=0; d<object_total; d++){

                    if (belongs_to[d] == c){
                        for (int e=0; e<features_total; e++){

                            new_centroids[c][e] += data[d][e];
                    
                        }
                    }
                }

                for (int f=0; f<features_total; f++){

                    if (cluster_size[c] > 0){

                        centroids[c][f] = (new_centroids[c][f]/(float)cluster_size[c]);        
                    }
                }

            }    
        }



    }

     return 0;
}
