
# Programming Competition Reference Document

![GitHub commit activity](https://img.shields.io/github/commit-activity/t/dirckvdende/competition-reference)
![GitHub last commit](https://img.shields.io/github/last-commit/dirckvdende/competition-reference)

This is a reference document which can be used for ICPC-style contests and other programming competitions. Before using this document, please check the following:

- Are you allowed to use a reference document during the competition. How many copies are you allowed to bring? Should you print pages one-sided or two-sided?
- Are you allowed to bring 25 pages of text, the length of this document?
- This reference document contains figures, images, and tables. Are you allowed to have those in your reference document?
- Is the text in this document the right size? This document should comply with ICPC standards.
- Are you allowed to have colors in the document? Printing the document in black-and-white should not have a significant impact on its usefulness.
- Are you allowed to use C++, the language used in most of this document? If yes, check the compiler version and arguments beforehand.

> [!CAUTION]
> If any of the points above pose a problem, you may need to edit the document yourself accordingly!

## Compilation and Customization

The reference document can be compiled from [main.tex](./main.tex) using PDFLatex, with [minted](https://www.overleaf.com/learn/latex/Code_Highlighting_with_minted) installed. Extra LaTeX packages may need to be installed if the document is not properly generated. If you prefer, there is also a makefile present.

There is a [config.tex](./config.tex) file present where the group name, university name, etc. can be changed. The logo displayed on the front page can be changed by changing the [logo.png](./logo.png) file. If you want to change the actual content of the reference document, edit the [content.tex](./content.tex) file. The [main.tex](./main.tex) file contains package information, configurations, and the front page content.

## Bugs and suggestions

For any bugs or suggestions, please create an issue or pull request on GitHub.

## License

This source code is distributed under an MIT license. See the [LICENSE](./LICENSE) file for more information.
