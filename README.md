
# **Git & GitHub 学习笔记：2025.8.7**

---

## 一、什么是 Git 与 GitHub？

### Git：
Git 是一个**分布式版本控制系统**，可以跟踪项目文件的历史修改记录。它支持离线操作、分支管理和多人协作开发。

### GitHub：
GitHub 是一个**基于 Git 的远程代码托管平台**，可以上传项目、共享代码、进行代码审查和协作开发。

### 区别与联系：
| 项目 | Git | GitHub |
|------|-----|--------|
| 类型 | 工具 | 平台 |
| 本地 | 本地 | 远程 |
| 离线 | 支持 | 不支持 |

---

##  二、本地 Git 仓库操作流程

```bash
# 创建项目文件夹并初始化
mkdir my-project
cd my-project
git init

# 添加文件并提交
echo "# My Project" > README.md
git add .
git commit -m "第一次提交"

# 绑定远程仓库并推送
git remote add origin https://github.com/用户名/my-project.git
git push -u origin main  # 或 master
```

---

##  三、分支管理

```bash
# 创建新分支并切换
git checkout -b dev

# 查看当前分支
git branch

# 推送分支到 GitHub
git push -u origin dev
```

---

##  四、C语言代码示例

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

---

## 📅 五、近五天学习成果表格（选做）

| 日期       | 学习内容           |  完成情况 |
|------------|--------------------|----------|
| 8月3日     | 机械结构知识，动力源的优缺点          |✅        |
| 8月4日     |   pcb，画电路板    |  ✅        |
| 8月5日     |   传感器相关知识，配置python的环境  |  ✅        |
| 8月6日     |      电控的基本知识，调试电机|  ✅        |
| 8月7日     | git github markdown |  ✅        |

---

## 🧩 六、软件安装情况汇报表😊😊😊💖💖💖

| 软件名称     | 是否已安装 | 
|--------------|------------|
| Git          |   ✅          |
| GitHub Desktop | ✅        | 
| VS Code      | ✅          | 
|Keil 5| ✅      | 
| DEV C++  | ✅          |

![截图，上传成功](WPS图片(1).png)