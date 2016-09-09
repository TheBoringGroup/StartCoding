import string
import re

# Constants
punctuation = string.punctuation
digits = string.digits
topics = {'gis':0, 'security':1, 'photo':2, 'mathematica':3, 'unix':4, 'wordpress':5, 'scifi':6, 'electronics':7, 'android':8, 'apple':9}

# Open training file
filein = open('training.json', 'r')
first = True
trainingData = []
classify = []

# Initialize the classify matrix
for i in range(10):
	classify.append({})

# Read training data from file
for dataset in filein:
	# Read the amount of training data in the file (first line)
	if first:
		trainingCount = dataset
		first = False

	# Append training data to list
	else:
		# Remove "title" words from each dataset
		string = dataset.find("topic")
		dataset = dataset[:string] + " " + dataset[string+5:]
		string = dataset.find("question")
		dataset = dataset[:string] + " " + dataset[string+8:]
		string = dataset.find("excerpt")
		dataset = dataset[:string] + " " + dataset[string+7:]

		# Remove string formatting characters
		while dataset.find("\\n") >= 0:
			string = dataset.find("\\n")
			dataset = dataset[:string] + " " + dataset[string+2:]
		while dataset.find("\\r") >= 0:
			string = dataset.find("\\r")
			dataset = dataset[:string] + " " + dataset[string+2:]
		while dataset.find("\\x") >= 0:
			string = dataset.find("\\x")
			dataset = dataset[:string] + " " + dataset[string+2:]

		# Special treatment for special characters (instances of this/that and contractions)
		while dataset.find("/") >= 0:
			string = dataset.find("/")
			dataset = dataset[:string] + " " + dataset[string+1:]
		while dataset.find("\'") >= 0:
			string = dataset.find("\'")
			dataset = dataset[:string] + " " + dataset[string+1:]

		# Remove all but alphabet characters and separate the words
		regex = re.compile('[^a-zA-Z]')
		dataset = regex.sub(' ', dataset)
		dataset = ''.join([char for char in dataset if not char in (punctuation or digits)]).split()

		# Get the current training set's topic ID and remove the topic word from the list
		topic = topics[dataset[0]]
		dataset = dataset[1:]

		# Populate classify matrix with training data
		for word in dataset:
			word = word.lower()
			if (len(word) > 3) and (word in classify[topic]):
				classify[topic][word] = classify[topic][word] + 1
			elif len(word) > 3:
				classify[topic][word] = 1

# We have the "trained" matrix
#TODO: Implement "learning" function

filein.close()