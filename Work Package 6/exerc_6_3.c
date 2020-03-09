#include<stdio.h>

#define ML13_Status 0x0B10
#define ML13_Control 0x0B00

int checkSensor(){
    if(ML13_Status == 0x0B08){//Sensor Triggered
        return 1;
    }
    return 0;
}

int wipe(){
    return 0x0B00;
}

void main () {

    int current_ML13_Status = ML13_Status;
    int current_ML13_Control = ML13_Control;
    int active = 1;

    while(active == 1){
        if(current_ML13_Control = 0x0B01){ //Open Doors
            current_ML13_Control = wipe();
            while(current_ML13_Status = 0x040){ //While opening
                for(int i = 0; i<1000; i++){}//Time for opening the door
                current_ML13_Status = 0x0B10; //At end of delay doors are open
            }
            for(int i = 0; i<1000; i++){ //Delay for open doors
                if(checkSensor()== 1){ //If sensor triggered
                    i = 0; //reset delay
                }
            }
            current_ML13_Control = 0x0B02; //Close doors
        }else if(current_ML13_Control = 0x0B02){ //Close Doors
            current_ML13_Control = wipe();
            current_ML13_Status = 0x0B20; //Initiate close
            while(current_ML13_Status = 0x0B80) { //While doors closing
                for(int i = 0; i<1000; i++) {//Time for doors closing
                    if (checkSensor() == 1) { //Sensor Triggered
                        current_ML13_Status = 0x0B08; //Sensor Triggered
                        current_ML13_Control = 0x0B01; //Initiate open
                        break; //Break out of delay
                    }
                }
                current_ML13_Status = 0x0B20; //Doors Closed
            }
        }
    }
}
