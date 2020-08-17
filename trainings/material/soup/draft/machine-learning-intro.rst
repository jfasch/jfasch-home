.. jf-topic:: drafts.ai.machine_learning_intro

Machine Learning: Concepts and Terminology
==========================================

.. contents::
   :local:

.. jf-topicgraph::
   :entries: drafts.ai.machine_learning_intro

Recommended Course
------------------

We only scratch the surface; see this video for much more. Beware
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

  * Works on unlabeled data. 
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
  * Example topic: :doc:`linear-regression/topic`

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
  * Example topic: :doc:`k-means`
