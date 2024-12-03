# Task 4 Branching Dialogue System

Advanced Programming

Ben Powell

2204331

Branching Dialogue


Looked at example of how to set up C# trees from the presentation.


Research the best way to set out the question data.

### Trees
- Specialized structure to store data in a hierarchical manner
- Central and sub nodes
- Have left and right nodes

Created big list of the nodes with questions.

Experimented the best way of connecting the nodes together.
Had some issue with changing the example tree code from the presentation into working for our purpose as our one, was a multi node layers. 
Had some issues with encapsulation, and getting the function to call the root node, by root being built at the start. Could then access the root and start the node traversal.
Some issues with the online compiler, but it seemed to work fine.
(Introduction to Tree Data Structure - GeeksforGeeks, s.d.)
```cpp
using System;
using System.Collections.Generic;

// The DialogueNode class represents a single dialogue option in the tree
public class DialogueNode
{
    // Task for student: Define the properties or fields for the dialogue node (e.g., dialogue text, choices, success/failure status)
    public string question;
    public DialogueNode yes, no;
    public bool endingNode;

    public DialogueNode(string NewDialogue, bool end) 
    {
        question = NewDialogue;
        yes = null;
        no = null;
        endingNode = end;
    }
    
}

// The DialogueSystem class represents the overall dialogue system
public class DialogueSystem
{
    // Task for student: Define the root node of the dialogue system (the starting point of the conversation)
    
    public DialogueNode BuildDialogueTree()
    {
        // Task for student: Build the dialogue tree structure here, creating connections between nodes
        DialogueNode root = new DialogueNode("Would you kill this person?", false);
        DialogueNode first = new DialogueNode("1How would you do it?",false); // yes
        DialogueNode second = new DialogueNode("2How wonderful?",false); //  no
        root.yes = first;
        root.no = second;
        
        DialogueNode third = new DialogueNode("3?",true); // yes
        DialogueNode fourth = new DialogueNode("4",false); // no
        first.yes = third;
        first.no = fourth;
        
        DialogueNode fifth = new DialogueNode("5",false); // yes, end
        DialogueNode sixth = new DialogueNode("6",true); // no
        second.yes = fifth;
        second.no = sixth;
        
        
        DialogueNode ninth = new DialogueNode("9",true); // yes, end
        DialogueNode tenth = new DialogueNode("10",true); // no, end
        fourth.yes = ninth;
        fourth.no = tenth;
        
        DialogueNode seventh = new DialogueNode("7",true); // yes, end
        DialogueNode eighth = new DialogueNode("8",true); // no, end 
        fifth.yes = seventh;
        fifth.no = eighth;
        
        return root;
        
        
    }
    
    public void StartDialogue(DialogueNode node)
    {
        // Task for student: Implement a function to navigate through the dialogue based on player choices
        string answer = "yes";
        
        if (node != null) {
            Console.WriteLine(node.question);
            answer = Console.ReadLine(); 
            if (answer == "yes")
            {
                StartDialogue(node.yes);
            }
            else
            {
                StartDialogue(node.no);
            }
        
        }
        
        
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        DialogueSystem dialogueSystem = new DialogueSystem();

        DialogueNode root = dialogueSystem.BuildDialogueTree();
         // Build the dialogue structure
        dialogueSystem.StartDialogue(root);     // Start navigating through the dialogue
    }
}
```
For an extra thing i wanted to create a input verification, so that anything that isnt yes or no would not be accepted or cause issues.


## Outcome
```cpp
using System;
using System.Collections.Generic;

// The DialogueNode class represents a single dialogue option in the tree
public class DialogueNode
{
    // Task for student: Define the properties or fields for the dialogue node (e.g., dialogue text, choices, success/failure status)
    public string question;
    public DialogueNode yes, no;
    public bool endingNode;

    public DialogueNode(string NewDialogue, bool end) 
    {
        question = NewDialogue;
        yes = null;
        no = null;
        endingNode = end;
    }
    
}

// The DialogueSystem class represents the overall dialogue system
public class DialogueSystem
{
    // Task for student: Define the root node of the dialogue system (the starting point of the conversation)
    
    public DialogueNode BuildDialogueTree()
    {
        // Task for student: Build the dialogue tree structure here, creating connections between nodes
        DialogueNode root = new DialogueNode("Would you kill this person?", false);
        DialogueNode first = new DialogueNode("Would you do it yourself?",false); // yes
        DialogueNode second = new DialogueNode("Help to save this person?",false); //  no
        root.yes = first;
        root.no = second;
        
        // first
        DialogueNode third = new DialogueNode("Would you like to run away?",false); // yes, end
        DialogueNode fourth = new DialogueNode("Would you hide the body?",false); // no
        first.yes = third;
        first.no = fourth;
        third.no = second;
        
        // second
        DialogueNode fifth = new DialogueNode("Would you sacrifice yourself?",false); // yes, end
        DialogueNode sixth = new DialogueNode("The police are coming, run quick?",false); // no
        second.yes = fifth;
        second.no = sixth;
        
        // fourth
        DialogueNode ninth = new DialogueNode("You have successfully survived",true); // yes, end
        DialogueNode tenth = new DialogueNode("The body was found",true); // no, end
        fourth.yes = ninth;
        fourth.no = tenth;
        third.yes = ninth;
        sixth.no = tenth;
        // fifth
        DialogueNode seventh = new DialogueNode("You have been killed, but you save someone",true); // yes, end
        DialogueNode eighth = new DialogueNode("The man has been killed, but you lived",true); // no, end 
        fifth.yes = seventh;
        fifth.no = eighth;
        
        return root;
        /* This sets up the tree, with a bool to determine if its an end node or not */
        
    }
    
    public void StartDialogue(DialogueNode node)
    {
        // Task for student: Implement a function to navigate through the dialogue based on player choices
        string answer = "empty";
        bool accepted = false;
        
        if (node != null) {
            
            while (accepted == false && node.endingNode == false)
            {
                Console.WriteLine(node.question);
                answer = Console.ReadLine(); 
                answer = answer.ToLower();
                if (answer == "yes")
                {
                    accepted = true;
                }
                else if (answer == "no")
                {
                    accepted = true;
                }
                else
                {
                Console.WriteLine("Please answer again with yes or no");
                
                }
                
            }
            
            if (answer == "yes")
            {
                StartDialogue(node.yes);
            }
            else if (answer == "no")
            {
                StartDialogue(node.no);
            }
            
            else
            {
                Console.WriteLine(node.question);
            }
            
        
        }
        
        /* this includes the validation of the input so it will only accept yes or no, which is pretty useful int stopping any errors caused by user input*/
        
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        DialogueSystem dialogueSystem = new DialogueSystem();

        DialogueNode root = dialogueSystem.BuildDialogueTree();
         // Build the dialogue structure
        dialogueSystem.StartDialogue(root);     // Start navigating through the dialogue
        Console.WriteLine("End of questions");
    }
}
```
## Output
Would you kill this person?<br>
yes<br>
Would you do it yourself?<br>
no<br>
Would you hide the body?<br>
yes<br>
You have successfully survived<br>
End of questions


## Reflection

I think i struggled a bit in how to layout and set up the tree, but eventually i got it to work. I think there is probably a better way to do it, if i rebuilt it. I think using diagrams to plan out how it should be helped understand how the tree should flow, but maybe more planning on how it should work and be implemented would have made it more clear.

Bibliograpy<br>
Introduction to Tree Data Structure - GeeksforGeeks (s.d.) At: https://www.geeksforgeeks.org/introduction-to-tree-data-structure/ (Accessed  03/12/2024).
