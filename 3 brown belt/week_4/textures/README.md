In the lectures, you saw the smart pointer shared_ptr, which provides shared ownership of an object. In this task, you will need to implement classes of shapes that can be drawn on the image, and which jointly own the given texture.

Among the files available to you, you will primarily be interested in the Common.h file. It provides an IShape interface that describes the shape. There are two kinds of shapes: rectangle and ellipse. They are listed in the ShapeType enumeration. Your task is to implement the MakeShape function, which creates a shape of a given view.

The IShape interface allows you to query and set a number of shape properties: position, size, and texture. It also allows you to clone a shape using the Clone () method. It is as if you would select a shape in the graphics editor and press Ctrl + C and Ctrl + V. The idea is that the inclined shape uses the same texture as the original. This is convenient because in general, a texture can take up a lot of memory. Of course, in the further inclined figure, you can set a new texture.

The texture object should be deleted at the moment when there are no more shapes that have the given texture. This can happen when you delete a shape, or when you assign a different texture to the shape.

In addition, the IShape interface allows you to draw the current shape on a given image using the Draw () method. Rendering occurs according to the following rules (see how_to_draw.png)

- The bounding rectangle is formed from the position and size of the figure
- Inside the bounding rectangle, a set of points belonging to the figure is formed - the shape of the figure (if the figure is a rectangle, then the shape of the figure coincides with the bounding rectangle)
- The texture is superimposed on the bounding box so that their upper left corner matches
- The image pixels that fall inside the shape of the shape are filled
- The pixels that are at the intersection of the shape of the shape and texture are filled with pixels of the texture (if there is no texture, we can assume that it is of zero size)
- The remaining pixels are filled with the default fill - the symbol "." (point)
- If any pixels go beyond the boundaries of the image, they are simply ignored.

As an example of proper rendering, you should look at the tests called from the main () function in the main.cpp file. In tests, a canvas is created (an instance of the Canvas class). Canvas is essentially an automated graphics editor that is managed through public methods. For example, the AddShape () method adds a new shape using the MakeShape () function that you need to implement. And the DuplicateShape () method clones an existing shape by calling the Clone () method, which, again, you will need to implement. Thus, with the help of tests it will be possible to verify the correctness of its implementation. However, be careful - as in other tasks, the successful completion of open tests is a necessary, but not sufficient condition for the correctness of your implementation. Describe your solution in the Solution.cpp file and send it for verification.

Comment

You can calculate the integer shape of an ellipse in different ways, so for definiteness, use the provided IsPointInEllipse () function.
