.. jf-topic:: python.drafts.ai.machine_learning_intro

Machine Learning: Concepts and Terminology
==========================================

.. contents::
   :local:

.. jf-topicgraph::
   :entries: python.drafts.ai.machine_learning_intro

This topic is an introductory one. We will only scratch the surface;
there is much terminology to learn, and this is what this topic is
about. Data science, machine learning, and artificial intelligence are
a very broad field, and there is much more to it.

See this video for a really good and thorough introduction. Beware
though, it is a whopping 4 hours long.

.. raw:: html

   <iframe
       width="560" 
       height="315" 
       src="https://www.youtube.com/embed/JMUxmLyrhSk" 
       frameborder="0" 
       allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" 
       allowfullscreen>
   </iframe>

Data scientists are not always known to be good (let alone diligent)
programmers. I have seen people use `Jupyter Notebooks
<https://jupyter.org/>`__ as editor and runtime environment for their
programs. While I like notebooks to play around, creating nicely
looking web pages with plots and charts *as a side effect* (really
cool), there is a point where one has to bite the bullet and start to
*program*. The latter is the focus of these AI topics.

See Also
--------

Concrete applications of the concepts and terminology introduced in
this topics can be found here:

* :doc:`linear-regression/topic`
* :doc:`k-means`

How Far Is Mankind from Creating God
------------------------------------

* **Artificial Narrow Intelligence** (ANI, Weak AI)

  * Stage that we are at now: can solve special problems
  * Weather forecast
  * Image recognition
  * Autonomous driving

* **Artificial General Intelligence** (AGI, Strong AI)
  
  * By far not there: can do everything a human can

* **Artificial Super Intelligence** (ASI)

  * `Terminator <https://en.wikipedia.org/wiki/The_Terminator>`__ and
    such

Basic Terminology: Algorithm and Model
--------------------------------------

* **Algorithm**. For example ...

  * Linear regression
  * Decision tree
  * Random forest
  * (many many more)

* **Model**. Trained by using an *algorithm*.

  * Uses the algorithm
  * Takes the input and maps it to output
  * Built through *training*.

Basic Terminology: Features and Data
------------------------------------

* **Input features** or *predictor variables*

  * Set of variables used as input to the model

* **Output features** or *response/target variables*

  * Set of variables calculated by the model, based on *input
    features*

* **Training Data**.

  * Used to create the model (the more the better)
  * Divided (*spliced*) into two parts

    * *Training data*; used to actually create/train the model
    * *Testing data*; used to test the efficiency/accuracy of it

Types of Machine Learning
-------------------------

* **Supervised Learning**. 

  * Each input training datum has its known/desired output attached as
    a *label*.
  * Used for regression and classification

* **Unsupervised Learning**.

  * Works on *unlabeled* data.
  * Creates clusters on its own, identifying features.
  * Used for association and clustering

* **Reinforcement Learning**. 

  * Agent learns from *actions* by measuring *rewards*. Rather
    advanced. No training. Trial and error.

Problems Solved
---------------

* **Regression**

  * *Output*: continuous quantity (usually a forecast of something)
  * Solved by *supervised learning* algorithms like *Linear
    Regression*.
  * See topic: :doc:`linear-regression/topic`

* **Classification**

  * *Output*: categorical quantity ("spam or not")
  * Solved by *supervised learning* algorithms like

    * Support Vector Machines
    * Naive Bayes
    * Logistic Regression
    * K Nearest Neighbor

* **Clustering**

  * *Output*: clusters of input data
  * Solved by *unsupervised learning* algorithms like K-means
  * See topic: :doc:`k-means`
