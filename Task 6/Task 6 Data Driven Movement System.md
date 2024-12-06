# Task 3 Data Driven Movement
Advanced Programming

Ben Powell

2204331

Data Driven Movement task


## Research

### Structs in c#
Data type that represents data structures.
Declared using struct keyword.
Revolve around having data, but not specifying behaviour like a object would.
They provide a means of "fastening together a group of independent-but-related variables" like a point (Assaad, 2010)
Value type so its faster than a class object(Struct in C#, 2020)


Chose to use C# for this task.
using data oriented design.
Involves feeding the data into functions rather than using objects
The entities have position and velocity data, and then figuring out the new distance using the time elapsed.
Attempted to mimic the for each in the print positions function, to access each struct and change it to the new distance
```cs
foreach (var entity in entities)
        {
            entity.PositionX = entity.PositionX + entity.VelocityX * deltaTime;
            entity.PositionY = entity.PositionY + entity.VelocityY * deltaTime;
            entity.PositionZ = entity.PositionZ + entity.VelocityZ * deltaTime;
        }
```
Changed it to this, it turned out you couldn't directly change the values. So a temp array is used and then the original struct is reassinged.


```cs 
// Implement logic to update the positions of all entities using their velocity and deltaTime
        for (int i = 0; i < entities.Count; i++)
        {
            // Retrieve the struct by reference
            var entity = entities[i];
        
            // Modify the struct fields
            entity.PositionX += entity.VelocityX * deltaTime;
            entity.PositionY += entity.VelocityY * deltaTime;
            entity.PositionZ += entity.VelocityZ * deltaTime;
        
            // Update the original list element with the modified struct
            entities[i] = entity;
        }
```
next up is enabling user inputted frame time, so it will get custom number of frames being run.





To make the program a bit more complicated i want to set a 'box' that has walls that cause the entities to bounce away. 

```cs
using System;
using System.Collections.Generic;

// Data struct for entity positions and velocities
public struct EntityData
{
    public float PositionX;
    public float PositionY;
    public float PositionZ;
    public float VelocityX;
    public float VelocityY;
    public float VelocityZ;

    public EntityData(float posX, float posY, float posZ, float velX, float velY, float velZ)
    {
        PositionX = posX;
        PositionY = posY;
        PositionZ = posZ;
        VelocityX = velX;
        VelocityY = velY;
        VelocityZ = velZ;
    }
}

// Movement system class
public class MovementSystem
{
    // Store the entities' data as a list
    public List<EntityData> entities = new List<EntityData>();

    // Task for student: Implement this function to update the positions of all entities based on their velocities
    public void UpdatePositions(float deltaTime)
    {
        // Implement logic to update the positions of all entities using their velocity and deltaTime
        for (int i = 0; i < entities.Count; i++)
        {
            // Retrieve the struct by reference
            var entity = entities[i];
        
            // Modify the struct fields
            entity.PositionX += entity.VelocityX * deltaTime;
            entity.PositionY += entity.VelocityY * deltaTime;
            entity.PositionZ += entity.VelocityZ * deltaTime;
        
            // Update the original list element with the modified struct
            entities[i] = entity;
        }
    }

    // Function to print the positions of all entities
    public void PrintPositions()
    {
        foreach (var entity in entities)
        {
            Console.WriteLine($"Entity Position: X={entity.PositionX}, Y={entity.PositionY}, Z={entity.PositionZ}");
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        // Initialize the MovementSystem and entities with sample data
        MovementSystem movementSystem = new MovementSystem();

        // Add some entities to the system
        movementSystem.entities.Add(new EntityData(0, 0, 0, 1, 0, 0));
        movementSystem.entities.Add(new EntityData(1, 2, 3, 0, 1, 0));
        movementSystem.entities.Add(new EntityData(5, 5, 5, 0, 0, 1));
        Console.WriteLine("How many frames?");
        int desFrame = Convert.ToInt32(Console.ReadLine());
        // Simulate multiple frames
        for (int frame = 0; frame < desFrame; frame++)
        {
            
            Console.WriteLine($"\nFrame {frame + 1}");
            
            movementSystem.PrintPositions();    // Print current positions
            movementSystem.UpdatePositions(1.016f);  // Update positions with deltaTime (16ms per frame)
            movementSystem.PrintPositions();  
        }
    }
}
```



_____________
|       /   |
|     /     |
|   /       |
| /         |
|___________|

|Y
_X
/Z

top / bot -  reverse Y velocity
left / right - reerse X velocity
front / back reverse Z velocity



10 by 10 by 10 box

```cs
if (entity.PositionX >= 10 || entity.PositionX <= 0)
            {
                entity.VelocityX = entity.VelocityX * -1;
            }
            
            entity.PositionY += entity.VelocityY * deltaTime;
            if (entity.PositionY >= 10 || entity.PositionY <= 0 )
            {
                entity.VelocityY = entity.VelocityY * -1;
            }
            entity.PositionZ += entity.VelocityZ * deltaTime;
            if (entity.PositionZ >= 10  || entity.PositionZ <= 0 )
            {
                
                entity.VelocityZ = entity.VelocityZ * -1;
            }
```        

This checks the values and reverses the velocity when  it gets to big or too small.
it does go over or under the values, so having a sort of bounce could be good.

```cs
for (int i = 0; i < entities.Count; i++)
        {
            // Retrieve the struct by reference
            var entity = entities[i];
        
            // Modify the struct fields
            entity.PositionX += entity.VelocityX * deltaTime;
            if (entity.PositionX >= 10 || entity.PositionX <= 0)
            { 
                if (entity.PositionX > 10)
                    {
                        entity.PositionX = 10;
                    }
                else if (entity.PositionX < 0) {
                    entity.PositionX = 0;
                }
                entity.VelocityX = entity.VelocityX * -1;
            }
            
            entity.PositionY += entity.VelocityY * deltaTime;
            if (entity.PositionY >= 10 || entity.PositionY <= 0 )
            {
                if (entity.PositionY > 10)
                    {
                        entity.PositionY = 10;
                    }
                else if (entity.PositionY < 0) {
                    entity.PositionY = 0;
                }
                entity.VelocityY = entity.VelocityY * -1;
            }
            entity.PositionZ += entity.VelocityZ * deltaTime;
            if (entity.PositionZ >= 10  || entity.PositionZ <= 0 )
            {
                if (entity.PositionZ > 10)
                    {
                        entity.PositionZ = 10;
                    }
                else if (entity.PositionZ < 0) {
                    entity.PositionZ = 0;
                }
                entity.VelocityZ = entity.VelocityZ * -1;
            }
        }
```

Want to add an acceleration and a time for that acceleration to happen over for each entity
had to look up equation of how best to use the speed and acceleration.

```cs
 Acceleration = acc;
        AccTime = aT;
if (entity.AccTime > 0)
            {
                entity.VelocityX = entity.VelocityX + entity.Acceleration;  
                entity.VelocityY = entity.VelocityY + entity.Acceleration;  
                entity.VelocityZ = entity.VelocityZ + entity.Acceleration; 
                entity.AccTime -= 1;
            }

```




Code
```cs

using System;
using System.Collections.Generic;

// Data struct for entity positions and velocities
public struct EntityData
{
    public float PositionX;
    public float PositionY;
    public float PositionZ;
    public float VelocityX;
    public float VelocityY;
    public float VelocityZ;
    public float Acceleration;
    public float AccTime;
    public EntityData(float posX, float posY, float posZ, float velX, float velY, float velZ, float acc, float aT)
    {
        PositionX = posX;
        PositionY = posY;
        PositionZ = posZ;
        VelocityX = velX;
        VelocityY = velY;
        VelocityZ = velZ;
        Acceleration = acc;
        AccTime = aT;
    }
}

// Movement system class
public class MovementSystem
{
    // Store the entities' data as a list
    public List<EntityData> entities = new List<EntityData>();

    // Task for student: Implement this function to update the positions of all entities based on their velocities
    public void UpdatePositions(float deltaTime)
    {
        // Implement logic to update the positions of all entities using their velocity and deltaTime
        for (int i = 0; i < entities.Count; i++)
        {
            // Retrieve the struct by reference
            var entity = entities[i];
        
            // Modify the struct fields
            entity.PositionX += entity.VelocityX * deltaTime;
            if (entity.PositionX >= 10 || entity.PositionX <= 0)
            { 
                if (entity.PositionX > 10)
                    {
                        entity.PositionX = 10;
                    }
                else if (entity.PositionX < 0) {
                    entity.PositionX = 0;
                }
                entity.VelocityX = entity.VelocityX * -1;
            }
            // checks whether the entity is within the box and if it has gone past the box it puts it onto the edge of the box 
            entity.PositionY += entity.VelocityY * deltaTime;
            if (entity.PositionY >= 10 || entity.PositionY <= 0 )
            {
                if (entity.PositionY > 10)
                    {
                        entity.PositionY = 10;
                    }
                else if (entity.PositionY < 0) {
                    entity.PositionY = 0;
                }
                entity.VelocityY = entity.VelocityY * -1;
            }
            entity.PositionZ += entity.VelocityZ * deltaTime;
            if (entity.PositionZ >= 10  || entity.PositionZ <= 0 )
            {
                if (entity.PositionZ > 10)
                    {
                        entity.PositionZ = 10;
                    }
                else if (entity.PositionZ < 0) {
                    entity.PositionZ = 0;
                }
                entity.VelocityZ = entity.VelocityZ * -1;
            }
            if (entity.AccTime > 0)
            {
                entity.VelocityX = entity.VelocityX + entity.Acceleration;  
                entity.VelocityY = entity.VelocityY + entity.Acceleration;  
                entity.VelocityZ = entity.VelocityZ + entity.Acceleration; 
                entity.AccTime -= 1;
            }
            
            // Changes the velocity of the by what the acceleration is and slows it down.
        
            // Update the original list element with the modified struct
            entities[i] = entity;
        }
    }

    // Function to print the positions of all entities
    public void PrintPositions()
    {
        foreach (var entity in entities)
        {
            Console.WriteLine($"Entity Position: X={entity.PositionX}, Y={entity.PositionY}, Z={entity.PositionZ}, Acceleration={entity.Acceleration}, AccelerationTime={entity.AccTime}");
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        // Initialize the MovementSystem and entities with sample data
        MovementSystem movementSystem = new MovementSystem();

        // Add some entities to the system
        movementSystem.entities.Add(new EntityData(0, 0, 0, 1, 0, 1, 1, 5));
        movementSystem.entities.Add(new EntityData(1, 2, 3, 1, 1, 0, 1, 4));
        movementSystem.entities.Add(new EntityData(5, 5, 5, 0, 1, 1, 1, 3));
        Console.WriteLine("How many frames?");
        int desFrame = Convert.ToInt32(Console.ReadLine());
        // Simulate multiple frames
        for (int frame = 0; frame < desFrame; frame++)
        {
            
            Console.WriteLine($"\nFrame {frame + 1}");
            
            movementSystem.PrintPositions();    // Print current positions
            movementSystem.UpdatePositions(1.016f);  // Update positions with deltaTime (16ms per frame)
            movementSystem.PrintPositions();  
        }
    }
}
```

## Outcome

How many frames?
25

Frame 1
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=5
Entity Position: X=1, Y=2, Z=3, Acceleration=1, AccelerationTime=4
Entity Position: X=5, Y=5, Z=5, Acceleration=1, AccelerationTime=3
Entity Position: X=1.016, Y=0, Z=1.016, Acceleration=1, AccelerationTime=4
Entity Position: X=2.016, Y=3.016, Z=3, Acceleration=1, AccelerationTime=3
Entity Position: X=5, Y=6.016, Z=6.016, Acceleration=1, AccelerationTime=2

Frame 2
Entity Position: X=1.016, Y=0, Z=1.016, Acceleration=1, AccelerationTime=4
Entity Position: X=2.016, Y=3.016, Z=3, Acceleration=1, AccelerationTime=3
Entity Position: X=5, Y=6.016, Z=6.016, Acceleration=1, AccelerationTime=2
Entity Position: X=3.048, Y=1.016, Z=3.048, Acceleration=1, AccelerationTime=3
Entity Position: X=4.048, Y=5.048, Z=4.016, Acceleration=1, AccelerationTime=2
Entity Position: X=6.016, Y=8.048, Z=8.048, Acceleration=1, AccelerationTime=1

Frame 3
Entity Position: X=3.048, Y=1.016, Z=3.048, Acceleration=1, AccelerationTime=3
Entity Position: X=4.048, Y=5.048, Z=4.016, Acceleration=1, AccelerationTime=2
Entity Position: X=6.016, Y=8.048, Z=8.048, Acceleration=1, AccelerationTime=1
Entity Position: X=6.096, Y=3.048, Z=6.096, Acceleration=1, AccelerationTime=2
Entity Position: X=7.096001, Y=8.096001, Z=6.048, Acceleration=1, AccelerationTime=1
Entity Position: X=8.048, Y=10, Z=10, Acceleration=1, AccelerationTime=0

Frame 4
Entity Position: X=6.096, Y=3.048, Z=6.096, Acceleration=1, AccelerationTime=2
Entity Position: X=7.096001, Y=8.096001, Z=6.048, Acceleration=1, AccelerationTime=1
Entity Position: X=8.048, Y=10, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=6.096, Z=10, Acceleration=1, AccelerationTime=1
Entity Position: X=10, Y=10, Z=9.096, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=7.968, Z=7.968, Acceleration=1, AccelerationTime=0

Frame 5
Entity Position: X=10, Y=6.096, Z=10, Acceleration=1, AccelerationTime=1
Entity Position: X=10, Y=10, Z=9.096, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=7.968, Z=7.968, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=10, Z=6.952, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.952, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=5.936, Z=5.936, Acceleration=1, AccelerationTime=0

Frame 6
Entity Position: X=6.952, Y=10, Z=6.952, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.952, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=5.936, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=4.92, Y=6.952, Z=4.92, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=3.904, Acceleration=1, AccelerationTime=0

Frame 7
Entity Position: X=4.92, Y=6.952, Z=4.92, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=3.904, Acceleration=1, AccelerationTime=0
Entity Position: X=2.888, Y=3.904, Z=2.888, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=1.872, Z=1.872, Acceleration=1, AccelerationTime=0

Frame 8
Entity Position: X=2.888, Y=3.904, Z=2.888, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=1.872, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=0.8559995, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=0

Frame 9
Entity Position: X=0.8559995, Y=0.8559995, Z=0.8559995, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=3.048, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=2.032, Z=2.032, Acceleration=1, AccelerationTime=0

Frame 10
Entity Position: X=0, Y=0, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=3.048, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=2.032, Z=2.032, Acceleration=1, AccelerationTime=0
Entity Position: X=2.032, Y=3.048, Z=2.032, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=6.096, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=4.064, Z=4.064, Acceleration=1, AccelerationTime=0

Frame 11
Entity Position: X=2.032, Y=3.048, Z=2.032, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=6.096, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=4.064, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=4.064, Y=6.096, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=9.144, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=6.096, Z=6.096, Acceleration=1, AccelerationTime=0

Frame 12
Entity Position: X=4.064, Y=6.096, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=9.144, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=6.096, Z=6.096, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=9.144, Z=6.096, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=10, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=8.128, Z=8.128, Acceleration=1, AccelerationTime=0

Frame 13
Entity Position: X=6.096, Y=9.144, Z=6.096, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=10, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=8.128, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=8.128, Y=10, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.952, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=10, Z=10, Acceleration=1, AccelerationTime=0

Frame 14
Entity Position: X=8.128, Y=10, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.952, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=10, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=6.952, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=7.968, Z=7.968, Acceleration=1, AccelerationTime=0

Frame 15
Entity Position: X=10, Y=6.952, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=7.968, Z=7.968, Acceleration=1, AccelerationTime=0
Entity Position: X=7.968, Y=3.904, Z=7.968, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=5.936, Z=5.936, Acceleration=1, AccelerationTime=0

Frame 16
Entity Position: X=7.968, Y=3.904, Z=7.968, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=5.936, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=5.936, Y=0.8559995, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=3.904, Z=3.904, Acceleration=1, AccelerationTime=0

Frame 17
Entity Position: X=5.936, Y=0.8559995, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=3.904, Z=3.904, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=0, Z=3.904, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=3.048, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=1.872, Z=1.872, Acceleration=1, AccelerationTime=0

Frame 18
Entity Position: X=3.904, Y=0, Z=3.904, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=3.048, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=1.872, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=1.872, Y=3.048, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=6.096, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=0, Z=0, Acceleration=1, AccelerationTime=0

Frame 19
Entity Position: X=1.872, Y=3.048, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=6.096, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=0, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=6.096, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=9.144, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=2.032, Z=2.032, Acceleration=1, AccelerationTime=0

Frame 20
Entity Position: X=0, Y=6.096, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=9.144, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=9.144, Y=2.032, Z=2.032, Acceleration=1, AccelerationTime=0
Entity Position: X=2.032, Y=9.144, Z=2.032, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=10, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=4.064, Z=4.064, Acceleration=1, AccelerationTime=0

Frame 21
Entity Position: X=2.032, Y=9.144, Z=2.032, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=10, Z=0, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=4.064, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=4.064, Y=10, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.952, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.096, Z=6.096, Acceleration=1, AccelerationTime=0

Frame 22
Entity Position: X=4.064, Y=10, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.952, Z=4.064, Acceleration=1, AccelerationTime=0
Entity Position: X=6.952, Y=6.096, Z=6.096, Acceleration=1, AccelerationTime=0
Entity Position: X=6.096, Y=6.952, Z=6.096, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=8.128, Z=8.128, Acceleration=1, AccelerationTime=0

Frame 23
Entity Position: X=6.096, Y=6.952, Z=6.096, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=3.904, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=3.904, Y=8.128, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=8.128, Y=3.904, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=10, Z=10, Acceleration=1, AccelerationTime=0

Frame 24
Entity Position: X=8.128, Y=3.904, Z=8.128, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=0.8559995, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=0.8559995, Y=10, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=10, Y=0.8559995, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=7.968, Z=7.968, Acceleration=1, AccelerationTime=0

Frame 25
Entity Position: X=10, Y=0.8559995, Z=10, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=0, Z=5.936, Acceleration=1, AccelerationTime=0
Entity Position: X=0, Y=7.968, Z=7.968, Acceleration=1, AccelerationTime=0
Entity Position: X=7.968, Y=0, Z=7.968, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=3.048, Z=1.872, Acceleration=1, AccelerationTime=0
Entity Position: X=3.048, Y=5.936, Z=5.936, Acceleration=1, AccelerationTime=0




## Reflection 
It was interesting to look at a problem using a slightly different design. Using structs of data fed into system that uses it to do things, is a different way of looking at it than using objects. I think visualising the problem when I created the box, helped me to better think out how the logic worked. I think I could probably use some functions to tidy up layout and flow of the program.

## Bibliography
Assaad, F. (2010) Answer to ‘What’s the difference between an object and a struct in OOP?’ At: https://stackoverflow.com/a/4514662 (Accessed  06/12/2024). Also Comment supercat 2014
Struct in C# (2020) At: https://www.tutorialsteacher.com/csharp/csharp-struct (Accessed  06/12/2024).
