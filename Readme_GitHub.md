$sudo apt-get install git
$git config --global user.name "Your user-name"
$git config --global user.email "your_email@youremail.com"
$git init
$git remote add origin https://github.com/user-name/my_project
&git remote -v
$touch my_file.cpp
$git status
&git add my_file.cpp
$git commit -m "Message to Explain this Version/Snapshot"



-===- Setup Git and Github for the First Time -===-
        
- Sign up for an account on GitHub.com, with user-name and email.
- Now install Git on your computer: 
    $sudo apt-get install git
- Now we have to run two setup commands:
    $git config --global user.name "Your user-name"
      It's good to use the same user-name you used on GitHub.com.
    $git config --global user.email "your_email@youremail.com"
      Use the same email you used on GitHub.com!


-===- Create a New Git and Github Project -===-

Creating Your Online GitHub Repository:
- Go to GitHub.com and login.
- Press the "+ New Repository" button.
- Now choose a short memorable name for your new project.
- Dont add any extra files, just click the green “Create Repository” button.

Creating Your Local Git Repository:
- make a good directory in you computer like:
    ~/Github_Projects/my_project
      Use the same name you used on GitHub for: my_project.
- Open the terminal in that directory and do:
    $git init
    
Connect Your Local Repository To Your GitHub Repository:
  - $git remote add origin https://github.com/user-name/my_project
  - To see what you repository connected to:
      &git remote -v


-===- Use Git -===- 

- Now make a new file in your project directory, you can use:
    $touch my_file.cpp
- To see what files Git is tracking:
    $git status
- To make Git start to track a file:
    $git add my_file.cpp
- To take a "snapshot" of the project:
    $git commit -m "Message to Explain this Version/Snapshot"
- To push you snapshot to GitHub:
    &git push
  or:
    &git push origin master





