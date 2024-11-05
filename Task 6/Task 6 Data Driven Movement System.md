Chose to use C# for this task.
using data oriented design.
Involves feeding the data into functions rather than using objects
The entities have position and velocity data, and then figuring out the new distance using the time elapsed.
Attempted to mimic the for eacch in the print positions function, to access each struct and change it to the new distance
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





To make the game a bit more complicated i want to set a 'box' that has walls that cause the entities to bounce away. 

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
```

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