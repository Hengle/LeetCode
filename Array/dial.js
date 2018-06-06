let fs = require("fs")
let path = require("path")
const dirname = "/home/tao/Dev/C++/LeetCode/LeetCode/Array"

let root = path.join(dirname)
readDir(root)

function readDir(path) {
    fs.readdir(path, function (err, files) {
        if (err) {
            return console.error(err)
        }
        files.forEach(function (file) {
            fs.stat(path + "/" + file, function (err, info) {
                if (info.isDirectory()) {
                    readSubDir(path + "/" + file)
                } else {
                    // console.log(file)
                }
            })
        })
    })
}
function readSubDir(path) {
    console.log("subdir ", path)
}