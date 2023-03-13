# Manual
This Latex repo is based on [TeXiFy IDEA](https://github.com/Hannah-Sten/TeXiFy-IDEA) (an IntelliJ IDEs Plugin). You can install the plugin on any IntelliJ editor, such as CLion or Pycharm. However, to compile the codes, ensure you have a basic TeX/LaTeX core on your computer. Relevant instructions is [here](https://github.com/Hannah-Sten/TeXiFy-IDEA/wiki/Installation).
### Configuration
Once you have installed the plugin and one Latex distribution, run a configuration as below, especially the "Main file to compile" & "Directory for output files" two paths. Then you may have a corresponding PDF generated. If not, feel free to ask me.
![image](config.png)
### Joint working
To make changes to the repo and avoid pushing directly to the main branch, it is recommended to use [GIT](https://git-scm.com/book/en/v2) and create a new branch. 

1. clone the main branch from GitHub
    ```
    cd <path-you-want-save>
    git clone https://github.com/UOL-Y2P-WearableSensor/Final-Report.git
    ```
2. create a new branch from the main branch and switch to that branch
    ```
    git checkout -b <new-branch-name>
    ```
3. apply modifications.
4. commit and pull this new branch to remote GitHub.
    ```
    git commit "<your-commit-title>"
    git push origin <new-branch-name>
    ```
5. [create new pull request](https://github.com/UOL-Y2P-WearableSensor/Final-Report/compare) from the new branch to main branch on GitHub.
6. compare the difference and push to the main branch.

If you're not familiar with GIT, you can use the [issue boards](https://github.com/UOL-Y2P-WearableSensor/Final-Report/issues) on GitHub or WhatsApp to discuss changes and coordinate with team members. This helps maintain the stability and integrity of the main branch, and allows for more organized and collaborative development.

