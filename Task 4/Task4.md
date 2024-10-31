Looked at example of how to set up C# trees from the presentation.


Research the best way to set out the question data.

Created big list of the nodes with questions.

Experimented the best way of connecting the nodes together.
Had some issue with changing the example tree code from the presentation into working for our purpose as our one, was a multi node layers. 
Had some issues with encapsulation, and getting the function to call the root node, by root being built at the start. Could then access the root and start the node traversal.
Some issues with the online compiler, but it seemed to work fine.

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
        DialogueNode second = new DialogueNode("Hand your self in?",false); //  no
        root.yes = first;
        root.no = second;
        
        // first
        DialogueNode third = new DialogueNode("Would you like to run away?",true); // yes, end
        DialogueNode fourth = new DialogueNode("Would you hide the body?",false); // no
        first.yes = third;
        first.no = fourth;
        third.no = first;
        
        // second
        DialogueNode fifth = new DialogueNode("Are you sure?",false); // yes, end
        DialogueNode sixth = new DialogueNode("",true); // no
        second.yes = fifth;
        second.no = sixth;
        
        // fourth
        DialogueNode ninth = new DialogueNode("9",true); // yes, end
        DialogueNode tenth = new DialogueNode("10",true); // no, end
        fourth.yes = ninth;
        fourth.no = tenth;
        
        
        // fifth
        DialogueNode seventh = new DialogueNode("7",true); // yes, end
        DialogueNode eighth = new DialogueNode("8",true); // no, end 
        fifth.yes = seventh;
        fifth.no = eighth;
        
        return root;
        
        
    }
    
    public void StartDialogue(DialogueNode node)
    {
        // Task for student: Implement a function to navigate through the dialogue based on player choices
        string answer = "empty";
        bool accepted = false;
        
        if (node != null) {
            Console.WriteLine(node.question);
            while (accepted == false )
            {
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
                Console.WriteLine(node.question);
                }
                
            }
            
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
        Console.WriteLine("End of questions");
    }
}
```
