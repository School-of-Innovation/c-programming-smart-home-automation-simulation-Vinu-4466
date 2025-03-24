/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 void initializeSystem(int rooms, int lights[], int temps[], int motion[], int locks[]);
 void setLight(int room, int rooms, int lights[], int state);
 void setTemperature(int room, int rooms, int temps[]);
 void setMotion(int room, int rooms, int motion[], int state);
 void lockUnlockDoor(int room, int rooms, int locks[]);
 void houseStatus(int rooms, int lights[], int temps[], int motion[], int locks[]);
 void checkEnergySaving(int rooms, int lights[], int *allLightsOnCount);
 void autoLock(int rooms, int motion[], int locks[], int *noMotionCount);
 
 int main() {
     int rooms, choice, room, state;
     
     // Taking user input for number of rooms
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
 
     // Declare Variable-Length Arrays (VLAs)
     int lights[rooms], temps[rooms], motion[rooms], locks[rooms];
 
     // Initialize system
     initializeSystem(rooms, lights, temps, motion, locks);
 
     int noMotionCount = 0, allLightsOnCount = 0;
 
     while (1) {
         // Display Menu
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Turn ON/OFF Light in a Room\n");
         printf("2. Set Temperature for a Room\n");
         printf("3. Manually Set Motion Detection\n");
         printf("4. Lock/Unlock a Door\n");
         printf("5. Check Entire House Status\n");
         printf("6. Enable Energy-Saving Mode Check\n");
         printf("7. Trigger Auto-Lock Check\n");
         printf("8. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
 
         switch (choice) {
             case 1:
                 printf("Enter room number (1-%d): ", rooms);
                 scanf("%d", &room);
                 printf("Enter 1 to turn ON, 0 to turn OFF: ");
                 scanf("%d", &state);
                 setLight(room - 1, rooms, lights, state);
                 break;
             case 2:
                 printf("Enter room number (1-%d): ", rooms);
                 scanf("%d", &room);
                 setTemperature(room - 1, rooms, temps);
                 break;
             case 3:
                 printf("Enter room number (1-%d): ", rooms);
                 scanf("%d", &room);
                 printf("Enter 1 for Motion Detected, 0 for No Motion: ");
                 scanf("%d", &state);
                 setMotion(room - 1, rooms, motion, state);
                 break;
             case 4:
                 printf("Enter room number (1-%d): ", rooms);
                 scanf("%d", &room);
                 lockUnlockDoor(room - 1, rooms, locks);
                 break;
             case 5:
                 houseStatus(rooms, lights, temps, motion, locks);
                 break;
             case 6:
                 checkEnergySaving(rooms, lights, &allLightsOnCount);
                 break;
             case 7:
                 autoLock(rooms, motion, locks, &noMotionCount);
                 break;
             case 8:
                 printf("Exiting...\n");
                 return 0;
             default:
                 printf("Invalid choice, try again.\n");
         }
     }
 }
 
 // Initialize system settings
 void initializeSystem(int rooms, int lights[], int temps[], int motion[], int locks[]) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;  // Lights OFF
         temps[i] = 22 + (i % 5);  // Simulated temperature variation
         motion[i] = 0;  // No motion detected
         locks[i] = 1;  // Doors LOCKED
     }
     printf("System Initialized!\n");
 }
 
 // Set light ON or OFF
 void setLight(int room, int rooms, int lights[], int state) {
     if (room >= 0 && room < rooms) {
         lights[room] = state;
         printf("Light in Room %d is now %s.\n", room + 1, lights[room] ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 // Set temperature for a room
 void setTemperature(int room, int rooms, int temps[]) {
     if (room >= 0 && room < rooms) {
         printf("Enter new temperature for Room %d: ", room + 1);
         scanf("%d", &temps[room]);
         printf("Temperature in Room %d set to %d°C.\n", room + 1, temps[room]);
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 // Manually set motion detection
 void setMotion(int room, int rooms, int motion[], int state) {
     if (room >= 0 && room < rooms) {
         motion[room] = state;
         printf("Motion status in Room %d is now %s.\n", room + 1, motion[room] ? "Detected" : "No Motion");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 // Lock or unlock doors
 void lockUnlockDoor(int room, int rooms, int locks[]) {
     if (room >= 0 && room < rooms) {
         locks[room] = !locks[room];
         printf("Door in Room %d is now %s.\n", room + 1, locks[room] ? "LOCKED" : "UNLOCKED");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 // Display the current status of all rooms
 void houseStatus(int rooms, int lights[], int temps[], int motion[], int locks[]) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
                lights[i] ? "ON" : "OFF", temps[i],
                motion[i] ? "Motion Detected" : "No Motion",
                locks[i] ? "Locked" : "Unlocked");
     }
 }
 
 // Check for energy-saving mode
 void checkEnergySaving(int rooms, int lights[], int *allLightsOnCount) {
     int allOn = 1;
     for (int i = 0; i < rooms; i++) {
         if (!lights[i]) {
             allOn = 0;
             break;
         }
     }
     if (allOn) {
         (*allLightsOnCount)++;
         if (*allLightsOnCount > 3) {
             printf("Energy Saving Mode: All lights have been ON for too long. Consider turning them off.\n");
             *allLightsOnCount = 0;
         }
     }
 }
 
 // Auto-lock doors if no motion is detected for a long time
 void autoLock(int rooms, int motion[], int locks[], int *noMotionCount) {
     int motionDetected = 0;
     for (int i = 0; i < rooms; i++) {
         if (motion[i]) {
             motionDetected = 1;
             break;
         }
     }
     if (!motionDetected) {
         (*noMotionCount)++;
         if (*noMotionCount >= 5) {
             for (int i = 0; i < rooms; i++) {
                 locks[i] = 1;
             }
             printf("Auto-Lock Activated: All doors are now LOCKED due to inactivity.\n");
             *noMotionCount = 0;
         }
     } else {
         *noMotionCount = 0;
     }
 }