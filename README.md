# DSL Practical Chits – C++ Solutions

Q1–Q16, one `.cpp` file per question.

## Run from the terminal
```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPO.git
cd YOUR_REPO
chmod +x dsl
./dsl 5        # compiles and runs Q05
./dsl list     # list all questions
```

## One-line command (no clone needed)
```bash
bash <(curl -s https://raw.githubusercontent.com/YOUR_USERNAME/YOUR_REPO/main/dsl) 5
```

## Permanent shortcut
```bash
echo "alias dsl='bash <(curl -s https://raw.githubusercontent.com/YOUR_USERNAME/YOUR_REPO/main/dsl)'" >> ~/.bashrc
source ~/.bashrc
dsl 12
```
(Use `~/.zshrc` instead of `~/.bashrc` on macOS/zsh.)

Requires `g++` (and `curl` for the no-clone mode).
