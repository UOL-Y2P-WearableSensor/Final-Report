# Manual
This Latex repo is based on [TeXiFy IDEA](https://github.com/Hannah-Sten/TeXiFy-IDEA) (an IntelliJ IDEs Plugin). You can install the plugin on any IntelliJ editor, such as CLion or Pycharm. However, to compile the codes, ensure you have a basic TeX/LaTeX core on your computer. Relevant instructions is [here](https://github.com/Hannah-Sten/TeXiFy-IDEA/wiki/Installation).
### Features of TeXiFy
1. [Writer ergonomics - writing LaTeX made less cumbersome](https://www.jetbrains.com/idea/features/)
2. [Forward search and backward search](https://github.com/Hannah-Sten/TeXiFy-IDEA/wiki/Built-in-pdf-viewer-support)
3. ...


### Configuration
Once you have installed the plugin and one Latex distribution, open the file ".run/pre.run.xml" in CLion. Save the config into your own project and run. Then you may have a corresponding PDF generated. If not, feel free to ask me.

### Joint working
To make changes to the repo and avoid pushing directly to the main branch, it is recommended to use [GIT](https://git-scm.com/book/en/v2) and create a new branch. 

1. Clone the main branch from GitHub
    ```
    cd <path-you-want-save>
    git clone https://github.com/UOL-Y2P-WearableSensor/Final-Report.git
    ```
2. Create a new branch from the main branch and switch to that branch
    ```
    git checkout -b <new-branch-name>
    ```
3. If you want to use an existed local branch, update the changes from remote main branch initially
   ```
   git pull origin main    //update changes from others
    ```
4. Apply modifications.
5. Commit and push this new branch to remote GitHub.
    ```
    git commit "<your-commit-title>"
    git push origin <new-branch-name>     //push your changes to remote non-main branch
    ```
6. Create [new pull request](https://github.com/UOL-Y2P-WearableSensor/Final-Report/compare) from the new branch to main branch on GitHub, using web browser (this step is on browser for convenient). Instruction is [here](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request).
7. Compare the difference and push to the main branch.

N.B: **For daily using, just repeat step 3 to 7.**

If you're not familiar with GIT, you can use the [issue boards](https://github.com/UOL-Y2P-WearableSensor/Final-Report/issues) on GitHub or WhatsApp to discuss changes and coordinate with team members. This helps maintain the stability and integrity of the main branch, and allows for more organized and collaborative development.

