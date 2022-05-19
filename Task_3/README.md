# Task 1 <br/>

<h1> 1. Problem Description </h1>
A 3D matrix is to be stored in a 1D vector (flattened). <br/>
The 3D matrix is of size n x m x p and is indexed by i, j, k. <br/>
The 1D vector is of size q and is indexed by y. <br/>

<h1> 2. Requirements </h1>
<p> Implement the following functions: </p>
<ol>
  <li> Create a 1D vector suitable for storing the 3D matrix. </li>
  <li> Convert the 3D matrix index (i, j, k) to a suitable 1D vector index (y). Must be O(1). </li>
</ol>

<p> I used C++ to conert 3D matrix to 1D vector </p>
<p> to get index of element in 1D vector we use this eqn: n*n*i + m*j + k </p>
