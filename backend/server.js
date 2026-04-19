const express = require("express");
const cors = require("cors");   // 🔥 bắt buộc
const { spawn } = require("child_process");
const path = require("path");

const app = express();

// 🔥 đặt TRƯỚC mọi route
app.use(cors({
    origin: "*",   // cho phép tất cả (dev cho dễ)
}));

app.use(express.json());
app.post("/run-bfs", (req, res) => {
    const { grid, start, end } = req.body;

    const rows = grid.length;
    const cols = grid[0].length;

    let input = `${rows} ${cols}\n`;

    for (let i = 0; i < rows; i++) {
        input += grid[i].join(" ") + "\n";
    }

    input += `${start.x} ${start.y}\n`;
    input += `${end.x} ${end.y}\n`;

    // 🔥 đường dẫn chuẩn
    const exePath = path.join(__dirname, "..", "algorithm", "bfs.exe");

    const process = spawn(exePath);

    let output = "";
    let errorOutput = "";

    process.stdin.write(input);
    process.stdin.end();

    process.stdout.on("data", (data) => {
        output += data.toString();
    });

    process.stderr.on("data", (data) => {
        errorOutput += data.toString();
    });

    process.on("close", (code) => {
        if (code !== 0) {
            console.error("Lỗi:", errorOutput);
            return res.status(500).send("Lỗi chạy BFS");
        }

        let lines = output.trim().split("\n");
        let n = parseInt(lines[0]);

        let pathResult = [];
        for (let i = 1; i <= n; i++) {
            let [x, y] = lines[i].split(" ").map(Number);
            pathResult.push({ x, y });
        }

        res.json({ path: pathResult });
    });
});

app.listen(3000, () => {
    console.log("Server chạy tại http://localhost:3000");
});