# C++ Homework uploads
這個專案主要是以 <Absolute C++ Sixth Edition> 這本書籍每個章節後的Programming Projects 選出幾題來做之後的解答為主
  
  按照課程的章節結構來組織代碼，每次提交包含一個或多個章節的解答

# Forms
每個資料夾的名稱會對應到其章節 內容有該章節後Programming Project其中幾題的.cpp檔答案
- 範例
-  CH4&CH5_HW/
  - - Q1.cpp
  - - Q2.cpp
  - - Q3.cpp
  
# 使用環境
在進行以下的使用方法時 皆會用到git
根據個人需求下載相應的版本
  
  下載網站 https://git-scm.com/

# 使用方法
若想要使用這些專題解答 可以使用以下方法
1. **複製檔案**：首先，您需要將專案的代碼複製到您的本地環境中。這可以通過使用`git clone`命令來完成。請在終端中執行以下命令：

        git clone <repository_url>     其中`<repository_url>`是專案在GitHub上的URL。
2. **進入到相應章節的資料夾**：專案中的每個章節都有一個對應的資料夾，資料夾的名稱對應到相應的章節。為了使用特定章節的解答，請進入到該章節的資料夾。例如，如果您想要使用第4章和第5章的解答，可以執行以下命令：

       cd CH4&CH5_HW

3. **新增、修復、更新或刪除文件**：一旦您進入到了相應章節的資料夾，您可以根據需要進行相應的操作。您可以添加新的功能或檔案、修復存在的問題、更新現有的文件或功能，或者刪除不再需要的文件或功能。請使用`git add`命令將您的更改添加到暫存區，然後使用`git commit`命令提交您的更改。例如：

       git add .
       git commit -m "Add solutions for chapter 4 and 5 exercises"

4. **將更改推送到GitHub**：一旦您完成了所需的更改並已經提交到本地存儲庫，您可以使用`git push`命令將您的更改推送到GitHub。請確保您有推送到的正確分支（通常是`main`或`master`分支）。例如：

       git push origin main

# 授權
這個專案使用MIT 授權

請隨意使用、修改和分發本專案中的代碼

有任何問題或建議，請隨時提出問題
